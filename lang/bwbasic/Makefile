# $NetBSD: Makefile,v 1.9 2005/09/28 17:00:36 rillig Exp $

PKGNAME=	${DISTNAME:=pl2}
DISTNAME=	bwbasic-2.20
CATEGORIES=	lang
MASTER_SITES=	http://www.nicholson.com/rhn/files/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jspath@bcpl.net
COMMENT=	The Bywater Basic interpreter

WRKSRC=		${WRKDIR}/bwbasic-2.20p2/bwbasic-2.20
DIST_SUBDIR=	${PKGNAME_NOREV}
GNU_CONFIGURE=	yes

SHARE_DIR=	${PREFIX}/share/bwbasic

pre-patch:
	${CP} ${WRKSRC}/../bwb-2.20-patch01/* ${WRKSRC}
	${CP} ${WRKSRC}/../bwb-2.20-patch02/* ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${SHARE_DIR}
	${CP} -r ${WRKSRC}/bwbtest ${SHARE_DIR}
	${FIND} ${SHARE_DIR} -type d -print | ${XARGS} ${CHMOD} ${BINMODE}
	${FIND} ${SHARE_DIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${INSTALL_MAN} ${WRKSRC}/bwbasic.doc ${PREFIX}/man/man1/bwbasic.1

.include "../../mk/bsd.pkg.mk"
