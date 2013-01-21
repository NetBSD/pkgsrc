# $NetBSD: Makefile,v 1.29 2013/01/21 00:07:31 dholland Exp $

DISTNAME=	craftcc35
PKGNAME=	craft-3.5
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	http://ibiblio.org/pub/linux/games/strategy/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
# Gone as of 20130120, no obvious replacement
#HOMEPAGE=	http://set.gmd.de/~hua/
COMMENT=	Warcraft-like game for X11

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++
USE_X11BASE=	yes

# Note for reference that there's a craftdoc.tar.Z that can also be
# downloaded; the only thing it contains that isn't in the main
# distfile is a few unreferenced images.

SUBST_CLASSES+=		craft
SUBST_STAGE.craft=	pre-configure
SUBST_FILES.craft=	win.hc setupedit.hc option_menu.hc craft_def.h
SUBST_VARS.craft=	PREFIX

SUBST_CLASSES+=		buttons
SUBST_STAGE.buttons=	pre-configure
SUBST_FILES.buttons=	.windefaults.params
SUBST_SED.buttons=	-e 's+buttons+${PREFIX}/share/craft/buttons+'

INSTALLATION_DIRS=	bin

post-extract:
	find ${WRKSRC} -type f -name '*~' -print | xargs rm -f
	ln -fs ${FILESDIR}/Makefile ${WRKSRC}
	for f in `find ${WRKSRC} -name "*.hc" -type f -print`; do	\
	  ${ECHO} "" >>$$f;						\
	done
	${CHMOD} a-x ${WRKSRC}/html/pic/*.gif
	${CHMOD} a-x ${WRKSRC}/html/pic/craft.gif.old
	${CHMOD} a-x ${WRKSRC}/html/craftcc.html
	rm -f ${WRKSRC}/hcc/hcc

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
