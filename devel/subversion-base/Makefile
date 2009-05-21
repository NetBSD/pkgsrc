# $NetBSD: Makefile,v 1.62 2009/05/21 16:11:41 abs Exp $

PKGNAME=	subversion-base-${SVNVER}
PKGREVISION=	3
COMMENT=	Version control system, base programs and libraries

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

# on at least solaris, configure fails to figure out
# that you need -lintl
BROKEN_GETTEXT_DETECTION=	yes

.include "../../devel/subversion/Makefile.common"

.if !empty(PKG_OPTIONS:Mapr1)
APU_OPTIONS=		PKG_BUILD_OPTIONS.apr-util
.else
APU_OPTIONS=		PKG_BUILD_OPTIONS.apr
.endif

BUILD_DEFS+=		${APU_OPTIONS}

USE_TOOLS+=		msgfmt

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
BUILDLINK_API_DEPENDS.neon+=	neon>=0.25.0
DAV_RA=				neon
.    include "../../www/neon/buildlink3.mk"
.  endif
.else
.  include "../../devel/apr0/buildlink3.mk"
BUILDLINK_API_DEPENDS.apr+=	apr>=0.9.5
BUILDLINK_API_DEPENDS.neon+=	neon>=0.25.0
DAV_RA=				neon
.  include "../../www/neon/buildlink3.mk"
.endif

.if !empty(${APU_OPTIONS}:Mdb4)
PLIST_SRC=		${PKGDIR}/PLIST ${PKGDIR}/PLIST.bdb
.else
CONFIGURE_ARGS+=	--without-berkeley-db
.endif

.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
.else
CONFIGURE_ARGS+=	--without-sasl
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
