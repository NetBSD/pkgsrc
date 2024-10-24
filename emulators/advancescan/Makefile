# $NetBSD: Makefile,v 1.1 2024/10/24 10:45:54 nia Exp $

DISTNAME=	advancescan-1.18
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=amadvance/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.advancemame.it/scan-readme
COMMENT=	Command line ROM manager for MAME derivatives
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

FORCE_CXX_STD=	gnu++98

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
