# $NetBSD: Makefile,v 1.16 2005/03/24 21:12:52 wiz Exp $

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
