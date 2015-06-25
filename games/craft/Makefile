# $NetBSD: Makefile,v 1.33 2015/06/25 06:22:11 dholland Exp $

DISTNAME=	craftcc35
PKGNAME=	craft-3.5
PKGREVISION=	4
CATEGORIES=	games x11
MASTER_SITES=	http://ibiblio.org/pub/linux/games/strategy/
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	http://www.NetBSD.org/~dholland/patchkits/craft/
PATCHFILES=	craft-jumbo-patch-20140913.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	pkgsrc-users@NetBSD.org
# Gone as of 20130120, no obvious replacement
#HOMEPAGE=	http://set.gmd.de/~hua/
COMMENT=	Warcraft-like game for X11

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
DEPENDS+=	netpbm>=10:../../graphics/netpbm
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--destdir=${DESTDIR} --prefix=${PREFIX}

# Note for reference that there's a craftdoc.tar.Z that can also be
# downloaded; the only thing it contains that isn't in the main
# distfile is a few unreferenced images.

# XXX: this calls system("csh -f -c ...") in a few places. These
# really ought to be patched out.
USE_TOOLS+=	csh:run

SUBST_CLASSES+=		buttons
SUBST_STAGE.buttons=	pre-configure
SUBST_FILES.buttons=	.windefaults.params
SUBST_SED.buttons=	-e 's+buttons+${PREFIX}/share/craft/buttons+'

INSTALLATION_DIRS=	bin

post-extract:
	find ${WRKSRC} -type f -name '*~' -print | xargs rm -f
	for f in `find ${WRKSRC} -name "*.hc" -type f -print`; do	\
	  ${ECHO} "" >> "$$f";						\
	done
	${CHMOD} a-x ${WRKSRC}/html/pic/*.gif
	${CHMOD} a-x ${WRKSRC}/html/pic/craft.gif.old
	${CHMOD} a-x ${WRKSRC}/html/craftcc.html
	rm -f ${WRKSRC}/hcc/hcc

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
