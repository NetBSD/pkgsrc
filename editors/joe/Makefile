# $NetBSD: Makefile,v 1.12 2001/11/29 01:12:31 hubertf Exp $
#

DISTNAME=	joe2.8
PKGNAME=	joe-2.8
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.std.com/src/editors/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	explorer@netbsd.org
COMMENT=	Joe's own editor

ALL_TARGET=	joe
WRKSRC=		${WRKDIR}/joe

CFLAGS+=	-DTERMINFO

.include "../../mk/bsd.pkg.mk"
