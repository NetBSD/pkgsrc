# $NetBSD: Makefile,v 1.6 2013/12/01 10:18:02 ryoon Exp $

PKGNAME=	subversion16-base-${SVNVER}
PKGREVISION=	3
COMMENT=	Version control system, base programs and libraries

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# on at least solaris, configure fails to figure out
# that you need -lintl
BROKEN_GETTEXT_DETECTION=	yes

.include "../../devel/subversion16/Makefile.common"

USE_TOOLS+=		msgfmt

CONFIGURE_ARGS+=	--disable-neon-version-check
CONFIGURE_ARGS+=	--without-apxs

.if !empty(PKG_OPTIONS:Mapr1)
APU_OPTIONS=		PKG_BUILD_OPTIONS.apr-util
.else
APU_OPTIONS=		PKG_BUILD_OPTIONS.apr
.endif
BUILD_DEFS+=		${APU_OPTIONS}

.if !empty(PKG_OPTIONS:Mapr1)
.  include "../../devel/apr/buildlink3.mk"
.  include "../../devel/apr-util/buildlink3.mk"
.else
BUILDLINK_API_DEPENDS.apr+=	apr>=0.9.5
.  include "../../devel/apr0/buildlink3.mk"
.endif

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.4
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

PLIST_VARS+=		db4
.if !empty(PKG_OPTIONS:Mapr1) && !empty(PKG_BUILD_OPTIONS.apr-util:Mdb4)
PLIST.db4=		yes
#CONFIGURE_ARGS+=	--with-berkeley-db=:${BUILDLINK_PREFIX.db4:Q}/include:${BUILDLINK_PREFIX.db4:Q}/lib:${BUILDLINK_LDADD.db4:S/^-l//:Q}
CONFIGURE_ARGS+=	--with-berkeley-db
.else
CONFIGURE_ARGS+=	--without-berkeley-db
.endif

PLIST_SUBST+=		DAV_RA=${DAV_RA:Q}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	contrib/cgi/tweak-log.cgi
SUBST_SED.paths=	-e "s|/usr/local/bin/|${PREFIX}/bin|g"
SUBST_MESSAGE.paths=	Fixing hardcoded /usr/local/bin paths.

RCD_SCRIPTS=	svnserve16

pre-configure:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

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
# Subversion's build system is set up to build everything from source
# at once.  In pkgsrc, we install the base part of subversion16, and
# then build other pieces against installed libraries.  Here, we run
# svn's equivalent of automake to say that the libraries installed as
# part of subversion16-base are installed, and save that generated file.
# Other packages then copy this file into place when building to avoid
# having to build these libraries again.
#
# The normal update procedure is
#   test build and package subversion16-base
#   run make svn-build-outputs-hack
#   test build and package other subversion16 packages
#   commit the update to ../subversion16/files/build-outputs.mk along with the version change
#
svn-build-outputs-hack:
	cd ${WRKSRC} && ./gen-make.py --release --installed-libs libsvn_client16,libsvn_delta16,libsvn_diff16,libsvn_fs16,libsvn_ra16,libsvn_repos16,libsvn_subr16,libsvn_wc16
	${MV} -f ${WRKSRC}/build-outputs.mk ${FILESDIR}/build-outputs.mk

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
