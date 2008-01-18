# $NetBSD: Makefile,v 1.51 2008/01/18 05:14:40 tnn Exp $

PKGNAME=	subversion-base-${SVNVER}
PKGREVISION=	3
COMMENT=	Version control system, base programs and libraries

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/subversion/Makefile.common"

.if !empty(PKG_OPTIONS:Mapr1)
APU_OPTIONS=		PKG_BUILD_OPTIONS.apr-util
.else
APU_OPTIONS=		PKG_BUILD_OPTIONS.apr
.endif

BUILD_DEFS+=		${APU_OPTIONS}

USE_TOOLS+=		msgfmt

# on at least solaris, configure fails to figure out
# that you need -lintl
BROKEN_GETTEXT_DETECTION=	yes

CONFIGURE_ARGS+=	--disable-neon-version-check
CONFIGURE_ARGS+=	--without-apache
CONFIGURE_ARGS+=	--without-apxs

.if !empty(PKG_OPTIONS:Mapr1)
.  include "../../devel/apr/buildlink3.mk"
.  include "../../devel/apr-util/buildlink3.mk"
.  if !empty(PKG_OPTIONS:Mserf)
DAV_RA=				serf
.    include "../../www/serf/buildlink3.mk"
.  else
BUILDLINK_API_DEPENDS.neon+=	neon>=0.24.7
DAV_RA=				dav
.    include "../../www/neon/buildlink3.mk"
.  endif
.else
.  include "../../devel/apr0/buildlink3.mk"
BUILDLINK_API_DEPENDS.apr+=	apr>=0.9.5
BUILDLINK_API_DEPENDS.neon+=	neon>=0.24.7
DAV_RA=				dav
.  include "../../www/neon/buildlink3.mk"
.endif

.if !empty(${APU_OPTIONS}:Mdb4)
PLIST_SRC=		${PKGDIR}/PLIST ${PKGDIR}/PLIST.bdb
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
	${INSTALL_DATA} ${WRKSRC}/tools/backup/hot-backup.py \
		${DESTDIR}${SVNEXAMPLES}/backup
	${INSTALL_DATA} ${WRKSRC}/contrib/cgi/tweak-log.cgi \
		${DESTDIR}${SVNEXAMPLES}/cgi
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/commit-email.pl \
		${DESTDIR}${SVNEXAMPLES}/hook-scripts
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/svnperms* \
		${DESTDIR}${SVNEXAMPLES}/hook-scripts

.PHONY: svn-build-outputs-hack
# Use this target to update the build-outputs.mk hack for sub-packages.
svn-build-outputs-hack:
	cd ${WRKSRC} && ./gen-make.py --release --installed-libs libsvn_client,libsvn_delta,libsvn_diff,libsvn_fs,libsvn_ra,libsvn_repos,libsvn_subr,libsvn_wc
	${MV} ${WRKSRC}/build-outputs.mk ${FILESDIR}/build-outputs.mk

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
