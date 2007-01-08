# $NetBSD: Makefile,v 1.2 2007/01/08 17:00:58 joerg Exp $

DISTNAME=	kasumi-1.0.1
CATEGORIES=	inputmethod japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=kasumi/20685/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kasumi.sourceforge.jp/
COMMENT=	Dictionary management tool for anthy

USE_TOOLS+=	pkg-config
USE_X11=	yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=	yes

USE_LANGUAGES+=	c c++

BUILDLINK_API_DEPENDS.anthy+=	anthy>=6520
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.4

.include "../../inputmethod/anthy/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
