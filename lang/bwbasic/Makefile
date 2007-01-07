# $NetBSD: Makefile,v 1.11 2007/01/07 09:13:56 rillig Exp $

PKGNAME=	${DISTNAME:=pl2}
DISTNAME=	bwbasic-2.20
CATEGORIES=	lang
MASTER_SITES=	http://www.nicholson.com/rhn/files/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jspath@bcpl.net
COMMENT=	The Bywater Basic interpreter

WRKSRC=		${WRKDIR}/bwbasic-2.20p2
BWBASIC_WRKSRC=	${WRKSRC}/bwbasic-2.20
DIST_SUBDIR=	${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	${BWBASIC_WRKSRC}
BUILD_DIRS=	${CONFIGURE_DIRS}

SHARE_DIR=	${PREFIX}/share/bwbasic

pre-patch:
	${CP} ${WRKSRC}/bwb-2.20-patch01/* ${BWBASIC_WRKSRC}
	${CP} ${WRKSRC}/bwb-2.20-patch02/* ${BWBASIC_WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${SHARE_DIR}
	${CP} -r ${BWBASIC_WRKSRC}/bwbtest ${SHARE_DIR}
	${FIND} ${SHARE_DIR} -type d -print | ${XARGS} ${CHMOD} ${BINMODE}
	${FIND} ${SHARE_DIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${INSTALL_MAN} ${BWBASIC_WRKSRC}/bwbasic.doc ${PREFIX}/${PKGMANDIR}/man1/bwbasic.1

.include "../../mk/bsd.pkg.mk"
