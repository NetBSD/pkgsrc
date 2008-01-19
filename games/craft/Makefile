# $NetBSD: Makefile,v 1.25 2008/01/19 09:16:20 wiz Exp $

DISTNAME=	craftcc35
PKGNAME=	craft-3.5
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	ftp://set.gmd.de/pub/as/janus/craft/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://set.gmd.de/~hua/
COMMENT=	Warcraft-like game for X11

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
USE_X11BASE=	yes

SUBST_CLASSES+=		craft
SUBST_STAGE.craft=	pre-configure
SUBST_FILES.craft=	win.hc setupedit.hc option_menu.hc craft_def.h
SUBST_VARS.craft=	PREFIX

SUBST_CLASSES+=		buttons
SUBST_STAGE.buttons=	pre-configure
SUBST_FILES.buttons=	.windefaults.params
SUBST_SED.buttons=	-e 's+buttons+${PREFIX}/share/craft/buttons+'

post-extract:
	find ${WRKSRC} -type f -name '*~' -print | xargs rm -f
	ln -fs ${FILESDIR}/Makefile ${WRKSRC}
	for f in `find ${WRKSRC} -name "*.hc" -type f -print`; do	\
	  ${ECHO} "" >>$$f;						\
	done

post-patch:
	rm -f ${WRKSRC}/hcc/hcc

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
BUILDLINK_TRANSFORM+=	rm:-lcompat
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
