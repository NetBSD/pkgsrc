# $NetBSD: Makefile,v 1.13 2003/03/29 12:40:43 jmmv Exp $
#

DISTNAME=	joe2.8
PKGNAME=	joe-2.8
PKGREVISION=	1
WRKSRC=		${WRKDIR}/joe
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.std.com/src/editors/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	explorer@netbsd.org
COMMENT=	Joe's own editor

ALL_TARGET=	joe

CFLAGS+=	-DTERMINFO

.include "../../mk/bsd.pkg.mk"
