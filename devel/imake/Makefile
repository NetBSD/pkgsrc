# $NetBSD: Makefile,v 1.13 2012/05/29 14:22:27 wiz Exp $

DISTNAME=		imake-1.0.5
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Imake and other utilities from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config makedepend:run

DEPENDS+=		xorg-cf-files>=1.0.3:../../x11/xorg-cf-files

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1
CONFIGURE_ENV+=		HAS_PERL=no

REPLACE_SH+=		mkhtmlindex.sh

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
# clang's cpp destroys whitespace, particularly hard tabs in makefiles,
# which is fatal for imake.
DEPENDS+=ucpp-[0-9]*:../../devel/ucpp
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="ucpp -s"

.elif empty(PKGSRC_COMPILER:Mgcc)
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="cc -E -Uunix -"

.endif

# This required with some C preprocessors and not others,
# but is harmless when not required.
SUBST_CLASSES+=		xmkmf
SUBST_MESSAGE.xmkmf=	Fixing "xmkmf" script.
SUBST_STAGE.xmkmf=	post-build
SUBST_FILES.xmkmf=	xmkmf
SUBST_SED.xmkmf=	-e "s/^configdirspec= */configdirspec=/"

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
