# $NetBSD: Makefile,v 1.1.1.1 2002/07/23 08:49:46 schmonz Exp $
#

.include "../../mail/ezmlm/Makefile.common"

DISTNAME=	ezmlm-idx-0.40
MASTER_SITES+=	http://gd.tuwien.ac.at/infosys/mail/qmail/ezmlm-patches/ \
		ftp://ftp.ezmlm.org/pub/patches/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ezmlm.org/
COMMENT=	ezmlm with enhancements by third parties

CONFLICTS=	ezmlm-[0-9]*

DISTFILES+=	${EZMLM_VERS}.tar.gz
PLIST_SRC+=	PLIST.idx

do-patch:
	@${MV} ${WRKSRC}/* ${WRKDIR}/${EZMLM_VERS}
	@${RMDIR} ${WRKSRC}
	@${MV} ${WRKDIR}/${EZMLM_VERS} ${WRKSRC}
	@cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < idx.patch

.include "../../mk/bsd.pkg.mk"
