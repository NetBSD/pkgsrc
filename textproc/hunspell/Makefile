# $NetBSD: Makefile,v 1.1.1.1 2007/09/11 17:40:29 wiz Exp $
#

DISTNAME=	hunspell-1.1.12-2
PKGNAME=	${DISTNAME:C/-([0-9]+)$/.\1/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hunspell/}

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://hunspell.sourceforge.net/
COMMENT=	Improved spellchecker

WRKSRC=			${WRKDIR}/${DISTNAME:C/-[0-9]+$//}
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-ui

PKGCONFIG_OVERRIDE+=	hunspell.pc.in

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
