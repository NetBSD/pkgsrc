# $NetBSD: Makefile,v 1.25 2025/04/21 16:21:40 wiz Exp $

DISTNAME=	sidplay-base-1.0.9
PKGNAME=	sidplay-1.0.9
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	https://web.archive.org/web/20040621034523/http://www.geocities.com:80/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20040628165954/http://www.geocities.com:80/SiliconValley/Lakes/5147/sidplay/
COMMENT=	Tools for playing sidtunes
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
