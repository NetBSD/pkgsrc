# $NetBSD: Makefile,v 1.18 2006/03/04 21:29:06 jlam Exp $

DISTNAME=	mpack-1.5-src
PKGNAME=	mpack-1.5
CATEGORIES=	converters mail news
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/mpack/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	External MIME packer/unpacker

WRKSRC=		${WRKDIR}/mpack

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
