# $NetBSD: Makefile,v 1.13 2004/03/29 18:08:33 epg Exp $

PKGNAME=	subversion-base-${SVNVER}
COMMENT=	Version control system, base programs and libraries

PLIST_SUBST+=   INSTALL_INFO=${INSTALL_INFO}

.include "../subversion/Makefile.common"

CONFIGURE_ARGS+=	--without-apache
CONFIGURE_ARGS+=	--without-apxs

# XXX Timestamps are broken in 1.0.1 tar file; should go away in 1.0.2.
post-build:
	${TOUCH} ${WRKSRC}/doc/programmer/design/svn-design.info

post-patch:
	${SED} -e 's|@BUILDLINK_PREFIX.db4@|${BUILDLINK_PREFIX.db4}|g' \
		< ${WRKSRC}/tools/backup/hot-backup.py.in \
		> ${WRKSRC}/tools/backup/hot-backup.py.in.new
	${MV} ${WRKSRC}/tools/backup/hot-backup.py.in.new \
		${WRKSRC}/tools/backup/hot-backup.py.in
	${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		< ${WRKSRC}/contrib/cgi/tweak-log.cgi \
		> ${WRKSRC}/contrib/cgi/tweak-log.cgi.new
	${MV} ${WRKSRC}/contrib/cgi/tweak-log.cgi.new \
		${WRKSRC}/contrib/cgi/tweak-log.cgi

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

BUILDLINK_DEPENDS.apr+=		apr>=0.9.5
BUILDLINK_DEPENDS.neon+=	neon>=0.24.1

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
