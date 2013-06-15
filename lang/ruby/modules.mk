# $NetBSD: modules.mk,v 1.34 2013/06/15 09:11:27 obache Exp $

.if !defined(_RUBY_MODULE_MK)
_RUBY_MODULE_MK=	# defined

.if defined(RUBY_RAILS_SUPPORTED)
USE_TOOLS+=		expr
.endif

.include "../../lang/ruby/rubyversion.mk"

#
# Default package name would prefixed by RUBY_PKGPREFIX.
#
PKGNAME?=	${RUBY_PKGPREFIX}-${DISTNAME}

.if defined(NO_BUILD) && empty(NO_BUILD:M[Nn][Oo])
DEPENDS+= ruby${RUBY_VER}-base>=${RUBY_VERSION}:../../lang/${RUBY_BASE}
.else
.include "../../lang/ruby/buildlink3.mk"
.endif

.if defined(RUBY_RAILS_SUPPORTED)
.include "../../lang/ruby/rails.mk"
.if ${RUBY_RAILS} > 3
RUBY_RDOC_REQD?=	2.5.0
.endif
.endif

#
# rdoc version
#
.include "../../lang/ruby/rdoc.mk"

CONFIGURE_ENV+=		RUBY=${RUBY:Q} RDOC=${RDOC:Q}

#
# extconf.rb support
#
# USE_RUBY_EXTCONF	Use extconf script.
#
# RUBY_EXTCONF		specify extconf script name (default: extconf.rb).
# RUBY_EXTCONF_CHECK	make sure to check existence of Makefile after
#			executing extconf script (default: yes).
# RUBY_EXTCONF_MAKEFILE	name of Makefile checked by RUBY_EXTCONF_CHECK
#			(default: Makefile)
#
.if defined(USE_RUBY_EXTCONF) && empty(USE_RUBY_EXTCONF:M[nN][oO])

RUBY_EXTCONF?=		extconf.rb
INSTALL_TARGET?=	site-install
CONFIGURE_ARGS+=	${RUBY_EXTCONF_ARGS}
RUBY_EXTCONF_ARGS?=	--with-opt-dir=${PREFIX:Q} --vendor
RUBY_EXTCONF_CHECK?=	yes
RUBY_EXTCONF_MAKEFILE?=	Makefile

do-configure:	ruby-extconf-configure

.if defined(RUBY_EXTCONF_SUBDIRS)
ruby-extconf-configure:
.for d in ${RUBY_EXTCONF_SUBDIRS}
	@${ECHO_MSG} "===>  Running ${RUBY_EXTCONF} in ${d} to configure"; \
	${ECHO_MSG} "${RUBY} ${RUBY_EXTCONF} ${CONFIGURE_ARGS}"
	${RUN}cd ${WRKSRC}/${d}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_EXTCONF} ${CONFIGURE_ARGS}
.if empty(RUBY_EXTCONF_CHECK:M[nN][oO])
	${RUN}cd ${WRKSRC}/${d}; \
		${TEST} -f ${RUBY_EXTCONF_MAKEFILE}
.endif
.endfor

.if !target(do-build)
do-build:	ruby-extconf-build

ruby-extconf-build:
.for d in ${RUBY_EXTCONF_SUBDIRS}
	@${ECHO_MSG} "===>  Building ${d}"
	${RUN}cd ${WRKSRC}/${d}; ${SETENV} ${MAKE_ENV} ${MAKE} ${BUILD_TARGET}
.endfor
.endif

.if !target(do-install)
do-install:	ruby-extconf-install

ruby-extconf-install:
.for d in ${RUBY_EXTCONF_SUBDIRS}
	@${ECHO_MSG} "===>  Installing ${d}"
	${RUN}cd ${WRKSRC}/${d}; ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET} ${INSTALL_MAKE_FLAGS}
.endfor
.endif

.else
ruby-extconf-configure:
	@${ECHO_MSG} "===>  Running ${RUBY_EXTCONF} to configure"; \
	${ECHO_MSG} "${RUBY} ${RUBY_EXTCONF} ${CONFIGURE_ARGS}"
	${RUN}cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_EXTCONF} ${CONFIGURE_ARGS}
.if empty(RUBY_EXTCONF_CHECK:M[nN][oO])
	${RUN}cd ${WRKSRC}/${d}; \
		${TEST} -f ${RUBY_EXTCONF_MAKEFILE}
.endif
.endif

#
# setup.rb support
#
# USE_RUBY_SETUP	Uset setup script.
# USE_RUBY_SETUP_PKG	Use pkgsrc's ruby-setup package.
#
# RUBY_SETUP		specify setup script name (default: setup.rb).
#
.elif defined(USE_RUBY_SETUP) && empty(USE_RUBY_SETUP:M[nN][oO])

RUBY_SETUP?=		setup.rb
RUBY_SETUP_SUBDIRS?=	.

.if defined(USE_RUBY_SETUP_PKG) && empty(USE_RUBY_SETUP_PKG:M[nN][oO])
BUILD_DEPENDS+=		${RUBY_PKGPREFIX}-setup>=3.4.0:../../devel/ruby-setup
.endif

.if !target(do-configure)
do-configure:	ruby-setup-configure

ruby-setup-configure:
.for d in ${RUBY_SETUP_SUBDIRS}
.if defined(USE_RUBY_SETUP_PKG) && empty(USE_RUBY_SETUP_PKG:M[nN][oO])
	@${ECHO_MSG} "===>  Use pkgsrc's ruby-setup"
	${RUN}cd ${WRKSRC}/${d}; \
		${CP} ${PREFIX}/${RUBY_VENDORLIB}/setup.rb ${RUBY_SETUP}
.endif
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to configure"
	${RUN}cd ${WRKSRC}/${d}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_SETUP} config ${CONFIGURE_ARGS}
.  endfor
.endif

.if !target(do-build)
do-build:	ruby-setup-build

ruby-setup-build:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to build"
.for d in ${RUBY_SETUP_SUBDIRS}
	${RUN}cd ${WRKSRC}/${d}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_SETUP} setup
.endfor
.endif

.if !target(do-install)
do-install:	ruby-setup-install

_RUBY_SETUP_INSTALLARGS=   ${INSTALL_TARGET}
.if ${_USE_DESTDIR} != "no"
_RUBY_SETUP_INSTALLARGS+=   --prefix=${DESTDIR:Q}
.endif

ruby-setup-install:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to ${INSTALL_TARGET}"
.for d in ${RUBY_SETUP_SUBDIRS}
	${RUN}cd ${WRKSRC}/${d}; \
	${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${RUBY} ${RUBY_SETUP} ${_RUBY_SETUP_INSTALLARGS}
.endfor
.endif

#
# install.rb support
#
# USE_RUBY_INSTALL	use simple install.rb script to install
#			(default: undefined)
# RUBY_SIMPLE_INSTALL	name of simple install.rb script (default: install.rb)
#
.elif defined(USE_RUBY_INSTALL) && empty(USE_RUBY_INSTALL:M[nN][oO])

RUBY_SIMPLE_INSTALL?=	install.rb
INSTALL_TARGET?=	# empty

SUBST_CLASSES+=		rinstall
SUBST_STAGE.rinstall=	pre-install
SUBST_FILES.rinstall=	${RUBY_SIMPLE_INSTALL}
SUBST_SED.rinstall=	-e "s|'sitedir'|'vendordir'|g"
SUBST_SED.rinstall+=	-e "s|'sitelibdir'|'vendorlibdir'|g"
SUBST_SED.rinstall+=	-e 's|"sitelibdir"|"vendorlibdir"|g'
SUBST_SED.rinstall+=	-e 's|/site_ruby/|/vendor_ruby/|g'
SUBST_MESSAGE.rinstall=	Fixing ${RUBY_SIMPLE_INSTALL} files.

.if !target(do-install)
do-install:	ruby-simple-install

ruby-simple-install:
	@${ECHO_MSG} "===>  Running ${RUBY_SIMPLE_INSTALL} to ${INSTALL_TARGET}"
	${RUN}cd ${WRKSRC}; \
	${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${RUBY} ${RUBY_SIMPLE_INSTALL} ${INSTALL_TARGET}
.endif
.endif # USE_RUBY_INSTALL

.if defined(USE_RAKE) && empty(USE_RAKE:M[nN][oO])

.if ${RUBY_VER} == "18"
.if !empty(USE_RAKE:M[Rr][Uu][Nn])
DEPENDS+=	${RUBY_PKGPREFIX}-rake>=0.8.7:../../devel/ruby-rake
.else
BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rake>=0.8.7:../../devel/ruby-rake
.endif
.endif

# RAKE
#	The path to the ``rake'' binary.
#
EVAL_PREFIX+=	RAKE_PREFIX=${RAKE_NAME}
RAKE=		${RAKE_PREFIX}/bin/${RAKE_NAME}
MAKE_ENV+=	RAKE=${RAKE:Q}
.endif

.include "replace.mk"
.endif
