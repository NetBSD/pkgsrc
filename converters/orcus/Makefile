# $NetBSD: Makefile,v 1.55 2026/01/28 22:00:21 mef Exp $

DISTNAME=	liborcus-0.21.0
PKGNAME=	${DISTNAME:S/liborcus/orcus/}
CATEGORIES=	converters
MASTER_SITES=	https://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/orcus/orcus
COMMENT=	Import filter library for spreadsheet documents
LICENSE=	mpl-2.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

# with gcc 7.5, we have following line:
# stream.cpp:191:44:   required from here
# /usr/include/g++/bits/unique_ptr.h:821:30: error: no matching function for call to 'orcus::file_content::impl::impl(std::basic_string_view<char16_t>&)'
#      { return unique_ptr<_Tp>(new _Tp(std::forward<_Args>(__args)...)); }

# implies gcc12
USE_CXX_FEATURES+=	c++20

# python detection completely broken
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_DIR.boost-libs}

PKGCONFIG_OVERRIDE+=	liborcus.pc.in
PKGCONFIG_OVERRIDE+=	liborcus-spreadsheet-model.pc.in

PTHREAD_AUTO_VARS=	yes

# strip the 3rd digit, may not work at all the cases
PLIST_SUBST+=		MAJOR_MINOR=${PKGVERSION_NOREV:C/.[0-9]$//}

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/libixion/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
