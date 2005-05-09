# $NetBSD: Makefile,v 1.25 2005/05/09 12:53:23 seb Exp $

PKGNAME=	subversion-base-${SVNVER}
COMMENT=	Version control system, base programs and libraries

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../subversion/Makefile.common"

BUILD_USES_MSGFMT=	yes

BUILD_DEFS+=		PKG_BUILD_OPTIONS.apr

CONFIGURE_ARGS+=	--without-apache
CONFIGURE_ARGS+=	--without-apxs

BUILDLINK_DEPENDS.apr+=		apr>=0.9.5
BUILDLINK_DEPENDS.neon+=	neon>=0.24.7

.include "../../devel/apr/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"

.if !empty(PKG_BUILD_OPTIONS.apr:Mdb4)
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

# Use this target to update the build-outputs.mk hack for sub-packages.
svn-build-outputs-hack:
	cd ${WRKSRC} && ./gen-make.py --installed-libs libsvn_client,libsvn_delta,libsvn_diff,libsvn_fs,libsvn_ra,libsvn_repos,libsvn_subr,libsvn_wc
	mv ${WRKSRC}/build-outputs.mk ${FILESDIR}/build-outputs.mk

.include "../../mk/bsd.pkg.mk"
