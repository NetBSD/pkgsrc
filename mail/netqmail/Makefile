# $NetBSD: Makefile,v 1.1.1.1 2004/07/21 22:42:04 schmonz Exp $
#

DISTNAME=	netqmail-1.05
CATEGORIES=	mail
MASTER_SITES=	http://qmail.org/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://qmail.org/netqmail/
COMMENT=	Unofficial distribution of qmail that includes basic patches

CONFLICTS+=	qmail-[0-9]*

USE_BUILDLINK3=	yes

# netqmail is a modification of the qmail source.
RESTRICTED=	"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_PACKAGE=	"needs work to function properly as a binary package"

WRKSRC=		${WRKDIR}/${DISTNAME}/${DISTNAME}

.include "../../mail/qmail/Makefile.common"

.if defined(PKG_PHASE) && ${PKG_PHASE} == "extract"
WRKSRC=		${WRKDIR}/${DISTNAME}
.endif

post-extract:
	@extract_file=qmail-1.03.tar.gz; export extract_file;		\
	cd ${WRKSRC}; ${EXTRACT_CMD}; cd qmail-1.03;			\
	${PATCH} ${PATCH_DIST_ARGS} < ../${DISTNAME}.patch;		\
	cd ..; ${MV} qmail-1.03 ${DISTNAME}

.include "../../mk/bsd.pkg.mk"
