# $NetBSD: Makefile,v 1.9 1999/05/08 18:20:34 ross Exp $
# FreeBSD Id: Makefile,v 1.3 1996/11/17 07:01:28 obrien Exp
#

DISTNAME=	joe2.8
PKGNAME=	joe-2.8
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.std.com/src/editors/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	explorer@netbsd.org

ALL_TARGET=	joe
WRKSRC=		${WRKDIR}/joe

CFLAGS+=	-DTERMINFO

.include "../../mk/bsd.pkg.mk"
