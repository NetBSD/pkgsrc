# $NetBSD: Makefile,v 1.14 2001/06/10 16:37:55 wiz Exp $
#

DISTNAME=       uudeview-0.5.15
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fpx.de/fp/Software/UUDeview/
COMMENT=	Program for uu/xx/Base64/BinHex de-/encoding

DEPENDS+=	uulib-0.5.15:../../converters/uulib

GNU_CONFIGURE=	Yes
CONFIGURE_ARGS=	--enable-inews=inews --disable-tcl
CONFIGURE_ENV=	LDFLAGS=-s

.include "../../mk/bsd.pkg.mk"
