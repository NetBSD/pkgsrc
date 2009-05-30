# $NetBSD: Makefile,v 1.63 2009/05/30 00:16:47 gdt Exp $

PKGNAME=	subversion-base-${SVNVER}
COMMENT=	Version control system, base programs and libraries

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

# on at least solaris, configure fails to figure out
# that you need -lintl
BROKEN_GETTEXT_DETECTION=	yes

.include "../../devel/subversion/Makefile.common"

USE_TOOLS+=		msgfmt

CONFIGURE_ARGS+=	--disable-neon-version-check
CONFIGURE_ARGS+=	--without-apxs

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.4
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

PLIST_VARS+=		db4
.if !empty(PKG_BUILD_OPTIONS.apr-util:Mdb4)
PLIST.db4=		yes
.else
CONFIGURE_ARGS+=	--without-berkeley-db
.endif

PLIST_SUBST+=		DAV_RA=${DAV_RA:Q}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	contrib/cgi/tweak-log.cgi
SUBST_SED.paths=	-e "s|/usr/local/bin/|${PREFIX}/bin|g"
SUBST_MESSAGE.paths=	Fixing hardcoded /usr/local/bin paths.

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${SVNDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} INSTALL README ${DESTDIR}${SVNDOC}
	cd ${WRKSRC}/doc/user && ${INSTALL_DATA} *.html *.txt ${DESTDIR}${SVNDOC}
	${INSTALL_DATA_DIR} ${DESTDIR}${SVNEXAMPLES}/backup
	${INSTALL_DATA_DIR} ${DESTDIR}${SVNEXAMPLES}/cgi
	${INSTALL_DATA_DIR} ${DESTDIR}${SVNEXAMPLES}/hook-scripts
	${INSTALL_DATA_DIR} ${DESTDIR}${SVNEXAMPLES}/hook-scripts/mailer
	${INSTALL_DATA_DIR} ${DESTDIR}${SVNEXAMPLES}/hook-scripts/mailer/tests
	${INSTALL_DATA} ${WRKSRC}/tools/backup/hot-backup.py \
		${DESTDIR}${SVNEXAMPLES}/backup
	${INSTALL_DATA} ${WRKSRC}/contrib/cgi/tweak-log.cgi \
		${DESTDIR}${SVNEXAMPLES}/cgi
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/commit* \
		${DESTDIR}${SVNEXAMPLES}/hook-scripts
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/svnperms* \
		${DESTDIR}${SVNEXAMPLES}/hook-scripts
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/log-police.py \
		${WRKSRC}/tools/hook-scripts/verify-po.py \
		${DESTDIR}${SVNEXAMPLES}/hook-scripts
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer/mailer* \
		${DESTDIR}${SVNEXAMPLES}/hook-scripts/mailer
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer/tests/mailer* \
		${DESTDIR}${SVNEXAMPLES}/hook-scripts/mailer/tests

.PHONY: svn-build-outputs-hack
# Use this target to update the build-outputs.mk hack for sub-packages.
svn-build-outputs-hack:
	cd ${WRKSRC} && ./gen-make.py --release --installed-libs libsvn_client,libsvn_delta,libsvn_diff,libsvn_fs,libsvn_ra,libsvn_repos,libsvn_subr,libsvn_wc
	${MV} ${WRKSRC}/build-outputs.mk ${FILESDIR}/build-outputs.mk

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
