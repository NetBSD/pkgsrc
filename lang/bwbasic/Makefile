# $NetBSD: Makefile,v 1.3 2002/05/20 10:39:36 wiz Exp $

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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/bwbasic
	${CP} -r ${WRKSRC}/bwbtest ${PREFIX}/share/bwbasic/
	${INSTALL_MAN} ${WRKSRC}/bwbasic.doc ${PREFIX}/man/man1/bwbasic.1

.include "../../mk/bsd.pkg.mk"
