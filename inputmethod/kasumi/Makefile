# $NetBSD: Makefile,v 1.46 2023/11/12 13:22:28 wiz Exp $

DISTNAME=	kasumi-2.5
PKGREVISION=	36
CATEGORIES=	inputmethod japanese
MASTER_SITES=	${MASTER_SITE_OSDN:=kasumi/41436/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://kasumi.osdn.jp/
COMMENT=	Dictionary management tool for anthy
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		pkg-config
USE_X11=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

BUILDLINK_API_DEPENDS.anthy+=	anthy>=6520
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6

.include "../../inputmethod/anthy/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
