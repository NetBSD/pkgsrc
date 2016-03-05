# $NetBSD: Makefile,v 1.101 2016/03/05 11:27:46 jperkin Exp $

PKGNAME=	subversion-base-${SVNVER}
PKGREVISION=	1
COMMENT=	Version control system, base programs and libraries

# on at least solaris, configure fails to figure out
# that you need -lintl
BROKEN_GETTEXT_DETECTION=	yes

.include "../../devel/subversion/Makefile.common"

USE_TOOLS+=		msgfmt

CONFIGURE_ARGS+=	--without-apxs

APU_OPTIONS=		PKG_BUILD_OPTIONS.apr-util
BUILD_DEFS+=		${APU_OPTIONS}

CFLAGS.SunOS+=		-D__EXTENSIONS__

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.7.15.1
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

PLIST_VARS+=		db4
.include "../../devel/apr-util/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.apr-util:Mdb4)
PLIST.db4=		yes
CONFIGURE_ARGS+=	--with-berkeley-db
.else
CONFIGURE_ARGS+=	--without-berkeley-db
.endif

PLIST_SUBST+=		DAV_RA=${DAV_RA:Q}

RCD_SCRIPTS=	svnserve

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
# at once.  In pkgsrc, we install the base part of subversion, and
# then build other pieces against installed libraries.  Here, we run
# svn's equivalent of automake to say that the libraries installed as
# part of subversion-base are installed, and save that generated file.
# Other packages then copy this file into place when building to avoid
# having to build these libraries again.
#
# The normal update procedure is
#   test build and package subversion-base
#   run make svn-build-outputs-hack
#   test build and package other subversion packages
#   commit the update to ../subversion/files/build-outputs.mk along with the version change
#
svn-build-outputs-hack:
	cd ${WRKSRC} && ./gen-make.py --release --installed-libs libsvn_client,libsvn_delta,libsvn_diff,libsvn_fs,libsvn_ra,libsvn_repos,libsvn_subr,libsvn_wc
	${MV} -f ${WRKSRC}/build-outputs.mk ${FILESDIR}/build-outputs.mk

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
