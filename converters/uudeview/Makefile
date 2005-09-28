# $NetBSD: Makefile,v 1.25 2005/09/28 20:52:18 rillig Exp $
#

DISTNAME=       uudeview-0.5.20
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fpx.de/fp/Software/UUDeview/
COMMENT=	Program for uu/xx/Base64/BinHex de-/encoding

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-inews=inews --disable-tcl
LDFLAGS+=		${_STRIPFLAG_CC}

.include "../../converters/uulib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
