# $NetBSD: Makefile,v 1.40 2018/11/12 03:52:22 ryoon Exp $
#

DISTNAME=	ibus-skk-1.4.3
PKGREVISION=	3
CATEGORIES=	inputmethod japanese
MASTER_SITES=	${MASTER_SITE_GITHUB:=ueno/}
GITHUB_PROJECT=	${PKGBASE}
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ueno/ibus-skk/
COMMENT=	Japanese SKK input engine for IBus
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-configure
SUBST_FILES.prefix=	src/preferences.c
SUBST_SED.prefix=	-e 's|/usr/share|${PREFIX}/share|g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/libskk/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
