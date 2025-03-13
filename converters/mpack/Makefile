# $NetBSD: Makefile,v 1.26 2025/03/13 17:52:47 maya Exp $

DISTNAME=	mpack-1.6
PKGREVISION=	4
CATEGORIES=	converters mail news
MASTER_SITES=	# ftp://ftp.andrew.cmu.edu/pub/mpack/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	External MIME packer/unpacker

GNU_CONFIGURE=		yes

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc)
CFLAGS+=	-Wno-error=implicit-int
CFLAGS+=	-Wno-error=implicit-function-declaration
.endif

.include "../../mk/bsd.pkg.mk"
