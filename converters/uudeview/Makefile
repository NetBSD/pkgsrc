# $NetBSD: Makefile,v 1.28 2008/06/01 21:49:56 dholland Exp $
#

DISTNAME=	uudeview-0.5.20
PKGREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fpx.de/fp/Software/UUDeview/
COMMENT=	Program for uu/xx/Base64/BinHex de-/encoding

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-inews=inews --disable-tcl
LDFLAGS+=		${_STRIPFLAG_CC}

.include "../../converters/uulib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
