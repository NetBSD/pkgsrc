# $NetBSD: Makefile,v 1.17 2002/03/24 03:11:06 fredb Exp $
#

DISTNAME=       uudeview-0.5.17
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fpx.de/fp/Software/UUDeview/
COMMENT=	Program for uu/xx/Base64/BinHex de-/encoding

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-inews=inews --disable-tcl
LDFLAGS+=		${_STRIPFLAG_CC}

.include "../../converters/uulib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
