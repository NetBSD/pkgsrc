# $NetBSD: Makefile,v 1.22 2004/11/23 04:21:34 jlam Exp $

PKGNAME=	subversion-base-${SVNVER}
COMMENT=	Version control system, base programs and libraries

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../subversion/Makefile.common"

CONFIGURE_ARGS+=	--without-apache
CONFIGURE_ARGS+=	--without-apxs

BUILDLINK_DEPENDS.apr+=		apr>=0.9.5
BUILDLINK_DEPENDS.neon+=	neon>=0.24.7

.include "../../devel/apr/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"

.if !empty(PKG_OPTIONS.apr:Mdb4)
PLIST_SRC=		${PKGDIR}/PLIST ${PKGDIR}/PLIST.bdb
.else
CONFIGURE_ARGS+=	--without-berkeley-db
.endif

SUBST_CLASSES=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=      contrib/cgi/tweak-log.cgi
SUBST_SED.paths=        -e "s|/usr/local/bin/|${PREFIX}/bin|g"
SUBST_MESSAGE.paths=    "Fixing hardcoded /usr/local/bin paths."

# Suppress attempt to build the .info documentation.
post-build:
	${TOUCH} ${WRKSRC}/doc/programmer/design/svn-design.info

post-install:
	${INSTALL_DATA_DIR} ${SVNDOC}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${SVNDOC}
	${INSTALL_DATA_DIR} ${SVNEXAMPLES}/backup
	${INSTALL_DATA_DIR} ${SVNEXAMPLES}/cgi
	${INSTALL_DATA_DIR} ${SVNEXAMPLES}/hook-scripts
	${INSTALL_DATA} ${WRKSRC}/tools/backup/hot-backup.py \
		${SVNEXAMPLES}/backup
	${INSTALL_DATA} ${WRKSRC}/contrib/cgi/tweak-log.cgi ${SVNEXAMPLES}/cgi
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/commit-email.pl \
		${SVNEXAMPLES}/hook-scripts
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/propchange-email.pl \
		${SVNEXAMPLES}/hook-scripts
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/svnperms* \
		${SVNEXAMPLES}/hook-scripts

.include "../../mk/bsd.pkg.mk"
