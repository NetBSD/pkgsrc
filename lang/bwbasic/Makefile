# $NetBSD: Makefile,v 1.4 2002/09/25 06:37:19 tron Exp $

DISTNAME=	bwbasic-2.20
WRKSRC=		${WRKDIR}/bwbasic-2.20p2/${PKGNAME_NOREV}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.rahul.net/pub/rhn/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jspath@bcpl.net
COMMENT=	The Bywater Basic interpreter

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
