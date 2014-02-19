# $NetBSD: Makefile,v 1.56 2014/02/19 15:47:32 taca Exp $

DISTNAME=	rubygems-2.0.10
PKGREVISION=	1
CATEGORIES=	misc ruby
MASTER_SITES=	http://production.cf.rubygems.org/rubygems/
EXTRACT_SUFX=	.tgz

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://rubygems.org/
COMMENT=	Ruby standard for publishing and managing third party libraries
LICENSE=	gnu-gpl-v2 OR ruby-license

CONFLICTS+=	rubygems-[0-9]*

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=	yes
NO_BUILD=	yes

REPLACE_RUBY_DIRS=	bin
REPLACE_RUBY_PAT=	[a-z]*

GEM_DOCDIR=	${GEM_HOME}/doc/${DISTNAME}

REQD_DIRS=	${GEM_HOME:H}
REQD_DIRS+=	${GEM_HOME}
REQD_DIRS+=	${GEM_HOME}/cache
REQD_DIRS+=	${GEM_HOME}/doc
REQD_DIRS+=	${GEM_HOME}/gems
REQD_DIRS+=	${GEM_HOME}/specifications

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	lib/rubygems/config_file.rb
SUBST_SED.conf=		-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.conf=	Fixing configuration files.

FILES_SUBST+=		RUBYGEM_NAME=${RUBYGEM_NAME}

# Generate a dynamic PLIST for the rubygems documentation directory.
GENERATE_PLIST+=	\
	${ECHO} "@comment The following lines are automatically generated." && \
	cd ${DESTDIR}${PREFIX} && \
	    if [ -d ${GEM_DOCDIR:S|${PREFIX}/||} ]; then \
		${FIND} ${GEM_DOCDIR:S|${PREFIX}/||} \! -type d -print | \
		${SORT}; \
	    else \
		:; \
	    fi

# Force the Gem repository to be under ${DESTDIR}.  This is harmless
# because this package depends on no other gems.
#
INSTALL_ENV+=		GEM_HOME=${DESTDIR}${PREFIX}/${GEM_HOME}
INSTALL_ENV+=		GEM_PATH=${DESTDIR}${PREFIX}/${GEM_HOME}

INSTALL_TARGET=		install
INSTALL_TARGET+=	--vendor --no-rdoc --no-ri
.if ${_USE_DESTDIR} != "no"
INSTALL_TARGET+=	--destdir=${DESTDIR:Q}
.endif

# rubygem's setup.rb is not the typical setup.rb -- manually run the
# command to install.
#
do-install:
	if [ -f ${DESTDIR}${PREFIX}/bin/${RUBYGEM_NAME} ]; then \
		${MV} ${DESTDIR}${PREFIX}/bin/${RUBYGEM_NAME} \
			${DESTDIR}${PREFIX}/bin/${RUBYGEM_NAME}.orig; \
	fi
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		${RUBY} setup.rb ${INSTALL_TARGET}
	${MV} ${DESTDIR}${PREFIX}/bin/${RUBYGEM_NAME} \
		 ${DESTDIR}${PREFIX}/bin/${RUBYGEM_NAME}.new
	if [ -f ${DESTDIR}${PREFIX}/bin/${RUBYGEM_NAME}.orig ]; then \
		${MV} ${DESTDIR}${PREFIX}/bin/${RUBYGEM_NAME}.orig \
			${DESTDIR}${PREFIX}/bin/${RUBYGEM_NAME}; \
	fi

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
