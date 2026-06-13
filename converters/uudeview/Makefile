# $NetBSD: Makefile,v 1.33 2026/06/13 14:40:29 wiz Exp $

DISTNAME=	uudeview-0.5.20
PKGREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hannob/uudeview
COMMENT=	Program for uu/xx/Base64/BinHex de-/encoding
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-inews=inews --disable-tcl
LDFLAGS+=		${_STRIPFLAG_CC}

CFLAGS+=		-DSTDC_HEADERS

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../converters/uulib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
