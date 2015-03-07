# $NetBSD: Makefile,v 1.20 2015/03/07 14:25:48 tnn Exp $

DISTNAME=		par2-0.6.11
CATEGORIES=		misc
USE_GITHUB=		yes
GH_ACCOUNT=		BlackIkeEagle
GH_PROJECT=		par2cmdline
GH_TAGNAME=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/BlackIkeEagle/par2cmdline
COMMENT=		PAR 2.0 compatible file verification and repair tool
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf automake autoreconf
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
