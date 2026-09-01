# $NetBSD: Makefile,v 1.27 2026/09/01 03:03:39 maya Exp $

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
.elif !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-implicit-function-declaration
.endif

.include "../../mk/bsd.pkg.mk"
