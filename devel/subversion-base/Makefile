# $NetBSD: Makefile,v 1.8 2003/12/06 03:01:58 epg Exp $

PKGNAME=	subversion-base-${SVNVER}
COMMENT=	Version control system, base programs and libraries

PLIST_SUBST+=   INSTALL_INFO=${INSTALL_INFO}

.include "../subversion/Makefile.common"

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

BUILDLINK_DEPENDS.apr?=		apr>=0.9.5
BUILDLINK_DEPENDS.neon?=	neon>=0.24.1

.include "../../databases/db4/buildlink2.mk"
.include "../../devel/apr/buildlink2.mk"
.include "../../www/neon/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
