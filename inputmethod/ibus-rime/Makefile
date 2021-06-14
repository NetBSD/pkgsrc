# $NetBSD: Makefile,v 1.23 2021/06/14 21:08:06 nia Exp $

GITHUB_PROJECT=	ibus-rime
$GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	ibus-rime-1.5.0
CATEGORIES=	inputmethod chinese
MASTER_SITES=	${MASTER_SITE_GITHUB:=rime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rime.im/
COMMENT=	Rime Input Method Engine for IBus
LICENSE=	gnu-gpl-v3

DEPENDS+=	rime-luna-pinyin-[0-9]*:../../inputmethod/rime-luna-pinyin

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-configure
SUBST_FILES.prefix=	rime.xml
SUBST_SED.prefix=	-e 's,/usr/,${PREFIX}/,g'

.include "../../inputmethod/librime/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
