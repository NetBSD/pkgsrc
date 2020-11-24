# $NetBSD: Makefile,v 1.12 2020/11/24 13:34:34 nia Exp $

DISTNAME=	ucpp-1.3.5
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/scarabeusiv/ucpp/uploads/79f08e39c676f15ed8a59335f6c9b924/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/scarabeusiv/ucpp
COMMENT=	C preprocessor and lexer
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-werror

PKGCONFIG_OVERRIDE+=	libucpp.pc.in

.include "../../mk/bsd.pkg.mk"
