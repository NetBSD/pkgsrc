# $NetBSD: Makefile,v 1.7 1998/09/22 06:11:36 garbled Exp $
# FreeBSD Id: Makefile,v 1.3 1996/11/17 07:01:28 obrien Exp
#

DISTNAME=	joe2.8
PKGNAME=	joe-2.8
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.std.com/src/editors/
EXTRACT_SUFX=	.tar.Z

NOT_FOR_ARCHS=	alpha	#gcc lossage

MAINTAINER=	explorer@netbsd.org

ALL_TARGET=	joe
WRKSRC=		${WRKDIR}/joe

CFLAGS+=	-DTERMINFO

.include "../../mk/bsd.pkg.mk"
