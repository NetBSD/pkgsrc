# $NetBSD: Makefile,v 1.15 2004/11/13 21:28:27 jlam Exp $
# FreeBSD Id: Makefile,v 1.7 1997/04/26 23:55:23 asami Exp
#

DISTNAME=	mpack-1.5-src
PKGNAME=	mpack-1.5
CATEGORIES=	converters mail news
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/mpack/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	External MIME packer/unpacker

WRKSRC=		${WRKDIR}/mpack
USE_BUILDLINK3=	yes

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
