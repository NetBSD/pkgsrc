# $NetBSD: Makefile,v 1.15 2001/08/20 02:18:56 jlam Exp $
#

DISTNAME=       uudeview-0.5.15
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fpx.de/fp/Software/UUDeview/
COMMENT=	Program for uu/xx/Base64/BinHex de-/encoding

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-inews=inews --disable-tcl
LDFLAGS+=		${STRIPFLAG}

.include "../../converters/uulib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
