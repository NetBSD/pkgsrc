# $NetBSD: Makefile,v 1.29 2010/01/29 16:54:40 joerg Exp $
#

DISTNAME=	uudeview-0.5.20
PKGREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fpx.de/fp/Software/UUDeview/
COMMENT=	Program for uu/xx/Base64/BinHex de-/encoding

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-inews=inews --disable-tcl
LDFLAGS+=		${_STRIPFLAG_CC}

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../converters/uulib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
