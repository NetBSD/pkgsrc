# $NetBSD: Makefile,v 1.24 2016/09/17 17:49:36 richard Exp $

DISTNAME=		imake-1.0.7
PKGREVISION=		3
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Imake and other utilities from modular X.org

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config makedepend:run

DEPENDS+=		tradcpp>=0.5.2:../../devel/tradcpp
DEPENDS+=		xorg-cf-files>=1.0.3:../../x11/xorg-cf-files

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1
CONFIGURE_ENV+=		HAS_PERL=no
CONFIGURE_ENV+=		RAWCPP=${PREFIX}/bin/tradcpp
CPPFLAGS+=		-DRAWCPP=\"${PREFIX}/bin/tradcpp\"

REPLACE_SH+=		mkhtmlindex.sh

# This required with some C preprocessors and not others,
# but is harmless when not required.
SUBST_CLASSES+=		xmkmf
SUBST_MESSAGE.xmkmf=	Fixing "xmkmf" script.
SUBST_STAGE.xmkmf=	post-build
SUBST_FILES.xmkmf=	xmkmf
SUBST_SED.xmkmf=	-e "s/^configdirspec= */configdirspec=/"

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
