# $NetBSD: Makefile,v 1.3 2017/08/18 21:04:51 adam Exp $

DISTNAME=	libidn2-2.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=libidn/}
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libidn/
COMMENT=	Convert internationalized domain names to/from ASCII Encoding
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libidn2.pc.in
INFO_FILES=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
