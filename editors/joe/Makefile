# $NetBSD: Makefile,v 1.15 2003/07/17 21:34:31 grant Exp $
#

DISTNAME=	joe2.8
PKGNAME=	joe-2.8
PKGREVISION=	2
WRKSRC=		${WRKDIR}/joe
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.std.com/src/editors/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	explorer@NetBSD.org
COMMENT=	Joe's own editor

ALL_TARGET=	joe

CFLAGS+=	-DTERMINFO

.include "../../mk/bsd.pkg.mk"
