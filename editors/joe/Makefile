# $NetBSD: Makefile,v 1.14 2003/06/08 15:20:40 abs Exp $
#

DISTNAME=	joe2.8
PKGNAME=	joe-2.8
PKGREVISION=	2
WRKSRC=		${WRKDIR}/joe
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.std.com/src/editors/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	explorer@netbsd.org
COMMENT=	Joe's own editor

ALL_TARGET=	joe

CFLAGS+=	-DTERMINFO

.include "../../mk/bsd.pkg.mk"
