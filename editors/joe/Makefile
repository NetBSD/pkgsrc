# $NetBSD: Makefile,v 1.8 1998/11/12 23:03:40 frueauf Exp $
# FreeBSD Id: Makefile,v 1.3 1996/11/17 07:01:28 obrien Exp
#

DISTNAME=	joe2.8
PKGNAME=	joe-2.8
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.std.com/src/editors/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	explorer@netbsd.org

NOT_FOR_ARCHS=	alpha	#gcc lossage

ALL_TARGET=	joe
WRKSRC=		${WRKDIR}/joe

CFLAGS+=	-DTERMINFO

.include "../../mk/bsd.pkg.mk"
