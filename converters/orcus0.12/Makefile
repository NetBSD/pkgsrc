# $NetBSD: Makefile,v 1.4 2016/10/07 18:25:40 adam Exp $

DISTNAME=	liborcus-0.12.0
PKGNAME=	${DISTNAME:S/liborcus/liborcus0.12/}
PKGREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://kohei.us/files/orcus/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/orcus/orcus
COMMENT=	Import filter library for spreadsheet documents (0.12 branch)
LICENSE=	mpl-2.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
# python detection completely broken
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-werror

PKGCONFIG_OVERRIDE+=	liborcus.pc.in
PKGCONFIG_OVERRIDE+=	liborcus-spreadsheet-model.pc.in

PTHREAD_AUTO_VARS=	yes

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds1.2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/libixion/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
