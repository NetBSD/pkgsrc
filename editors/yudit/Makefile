# $NetBSD: Makefile,v 1.30 2023/08/02 19:20:19 nia Exp $

DISTNAME=	yudit-2.9.2
CATEGORIES=	editors
MASTER_SITES=	http://yudit.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yudit.org/
COMMENT=	Unicode Text Editor
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake msgmerge
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-x

# Fails with C++14 default language.
FORCE_CXX_STD=		c++03

BUILDLINK_DEPMETHOD.libXt=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
