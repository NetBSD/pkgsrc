# $NetBSD: Makefile,v 1.24 2005/04/11 21:45:10 tv Exp $
#

DISTNAME=       uudeview-0.5.20
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fpx.de/fp/Software/UUDeview/
COMMENT=	Program for uu/xx/Base64/BinHex de-/encoding

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-inews=inews --disable-tcl
LDFLAGS+=		${_STRIPFLAG_CC}

.include "../../converters/uulib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
