# $NetBSD: Makefile,v 1.32 2023/06/30 06:31:20 wiz Exp $

DISTNAME=		imake-1.0.9
PKGREVISION=		1
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Obsolete build tool for X software

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config makedepend:run

TOOL_DEPENDS+=		tradcpp>=0.5.2:../../devel/tradcpp
DEPENDS+=		tradcpp>=0.5.2:../../devel/tradcpp
DEPENDS+=		xorg-cf-files>=1.0.3:../../x11/xorg-cf-files

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1
CONFIGURE_ENV+=		HAS_PERL=no
CONFIGURE_ENV+=		RAWCPP=${TOOLBASE:Q}/bin/tradcpp

# The configure script wants to run tradcpp to test its
# characteristics, but what gets baked into the package needs to be
# where tradcpp will live at run-time.
CPPFLAGS+=		-DRAWCPP=\"${PREFIX:Q}/bin/tradcpp\"
MAKE_FLAGS+=		RAWCPP=${PREFIX:Q}/bin/tradcpp

REPLACE_SH+=		mkhtmlindex.sh

# This required with some C preprocessors and not others,
# but is harmless when not required.
SUBST_CLASSES+=		xmkmf
SUBST_MESSAGE.xmkmf=	Fixing "xmkmf" script.
SUBST_STAGE.xmkmf=	post-build
SUBST_FILES.xmkmf=	xmkmf
SUBST_SED.xmkmf=	-e "s/^configdirspec= */configdirspec=/"
SUBST_NOOP_OK.xmkmf=	yes

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
