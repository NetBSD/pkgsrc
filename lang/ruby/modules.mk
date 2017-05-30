# $NetBSD: modules.mk,v 1.41 2017/05/30 16:02:00 taca Exp $
#
#
# Package-settable variables:
#
#
# USE_RUBY_EXTCONF	Use extconf script.
#
# RUBY_EXTCONF		specify extconf script name (default: extconf.rb).
# RUBY_EXTCONF_CHECK	make sure to check existence of Makefile after
#			executing extconf script (default: yes).
# RUBY_EXTCONF_DEBUG	variable for trigger Ruby debuger for extconf.
# RUBY_EXTCONF_MAKEFILE	name of Makefile checked by RUBY_EXTCONF_CHECK
#			(default: Makefile)
#
# USE_RUBY_SETUP	Uset setup script.
# USE_RUBY_SETUP_PKG	Use pkgsrc's ruby-setup package.
#
# RUBY_SETUP		specify setup script name (default: setup.rb).
#
#
# USE_RUBY_INSTALL	use simple install.rb script to install
#			(default: undefined)
# RUBY_SIMPLE_INSTALL	name of simple install.rb script (default: install.rb)
#
#
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
DEPENDS+= ${RUBY_BASE}>=${RUBY_VERSION}:${RUBY_SRCDIR}
.else
.include "../../lang/ruby/buildlink3.mk"
.endif

.if defined(RUBY_RAILS_SUPPORTED)
.include "../../lang/ruby/rails.mk"
.endif

CONFIGURE_ENV+=		RUBY=${RUBY:Q} RDOC=${RDOC:Q}

# extconf.rb support
#
.if defined(USE_RUBY_EXTCONF) && empty(USE_RUBY_EXTCONF:M[nN][oO])

RUBY_EXTCONF?=		extconf.rb
INSTALL_TARGET?=	site-install
CONFIGURE_ARGS+=	${RUBY_EXTCONF_ARGS}
RUBY_EXTCONF_ARGS?=	--with-opt-dir=${PREFIX:Q} --vendor
RUBY_EXTCONF_CHECK?=	yes
RUBY_EXTCONF_DEBUG?=	# -r debug
RUBY_EXTCONF_MAKEFILE?=	Makefile

do-configure:	ruby-extconf-configure

.if defined(RUBY_EXTCONF_SUBDIRS)
ruby-extconf-configure:
.for d in ${RUBY_EXTCONF_SUBDIRS}
	@${ECHO_MSG} "===>  Running ${RUBY_EXTCONF} in ${d} to configure"; \
	${ECHO_MSG} "${RUBY} ${RUBY_EXTCONF_DEBUG} ${RUBY_EXTCONF} ${CONFIGURE_ARGS}"
	${RUN}cd ${WRKSRC}/${d}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_EXTCONF_DEBUG} ${RUBY_EXTCONF} ${CONFIGURE_ARGS}
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
	${ECHO_MSG} "${RUBY} ${RUBY_EXTCONF_DEBUG} ${RUBY_EXTCONF} ${CONFIGURE_ARGS}"
	${RUN}cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_EXTCONF_DEBUG} ${RUBY_EXTCONF} ${CONFIGURE_ARGS}
.if empty(RUBY_EXTCONF_CHECK:M[nN][oO])
	${RUN}cd ${WRKSRC}/${d}; \
		${TEST} -f ${RUBY_EXTCONF_MAKEFILE}
.endif
.endif

#
# setup.rb support
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
_RUBY_SETUP_INSTALLARGS+=   --prefix=${DESTDIR:Q}

ruby-setup-install:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to ${INSTALL_TARGET}"
.for d in ${RUBY_SETUP_SUBDIRS}
	${RUN}cd ${WRKSRC}/${d}; \
	${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${RUBY} ${RUBY_SETUP} ${_RUBY_SETUP_INSTALLARGS}
.endfor
.endif

#
# install.rb support
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

.include "replace.mk"
.endif
