# $NetBSD: Makefile,v 1.16 2004/01/20 12:14:05 agc Exp $
#

DISTNAME=	joe2.8
PKGNAME=	joe-2.8
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.std.com/src/editors/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	explorer@NetBSD.org
COMMENT=	Joe's own editor

WRKSRC=		${WRKDIR}/joe
ALL_TARGET=	joe

CFLAGS+=	-DTERMINFO

.include "../../mk/bsd.pkg.mk"
