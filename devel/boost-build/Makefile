# $NetBSD: Makefile,v 1.6 2008/01/04 19:58:39 jmmv Exp $
#

BOOST_PACKAGE=		build
BOOST_COMMENT=		(Boost.Build framework)
BOOST_CONFIG=		no

.include "../../meta-pkgs/boost/Makefile.common"

SUBST_CLASSES+=		confdir
SUBST_MESSAGE.confdir=	Fixing path to site-config.jam.
SUBST_STAGE.confdir=	pre-build
SUBST_FILES.confdir=	tools/build/v2/build-system.jam
SUBST_SED.confdir=	-e 's,/etc,${PKG_SYSCONFDIR},g'

EGDIR=			${PREFIX}/share/examples/boost-build
CONF_FILES=		${EGDIR}/site-config.jam \
			${PKG_SYSCONFDIR}/site-config.jam

.include "toolset.mk"

post-extract:
	${FIND} ${WRKSRC}/tools/build/v2 -type d -exec ${CHMOD} 755 {} \;
	${FIND} ${WRKSRC}/tools/build/v2 -type f -exec ${CHMOD} 644 {} \;

do-build:
	{ ${ECHO} '# System wide configuration file for Boost.Build.' ; \
	  ${ECHO} ; \
	  ${ECHO} 'using ${BOOST_TOOLSET} ;' ; } >${WRKDIR}/site-config.jam

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/boost-build
	cd ${WRKSRC}/tools/build/v2 && ${PAX} -rw -pp -pm . \
	    ${PREFIX}/share/boost-build
	find ${PREFIX}/share/boost-build -name "*.orig" -exec rm "{}" \;
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/site-config.jam ${EGDIR}

.include "../../mk/bsd.pkg.mk"
