# $NetBSD: Makefile,v 1.6 2004/01/20 12:19:16 agc Exp $

DISTNAME=	bwbasic-2.20
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.rahul.net/pub/rhn/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jspath@bcpl.net
COMMENT=	The Bywater Basic interpreter

WRKSRC=		${WRKDIR}/bwbasic-2.20p2/${PKGNAME_NOREV}
DIST_SUBDIR=	${PKGNAME_NOREV}
GNU_CONFIGURE=	yes

SHARE_DIR=	${PREFIX}/share/bwbasic

post-install:
	${INSTALL_DATA_DIR} ${SHARE_DIR}
	${CP} -r ${WRKSRC}/bwbtest ${SHARE_DIR}
	${FIND} ${SHARE_DIR} -type d | ${XARGS} ${CHMOD} ${BINMODE}
	${FIND} ${SHARE_DIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	${INSTALL_MAN} ${WRKSRC}/bwbasic.doc ${PREFIX}/man/man1/bwbasic.1

.include "../../mk/bsd.pkg.mk"
