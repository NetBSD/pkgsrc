# $NetBSD: Makefile,v 1.28 2006/01/24 07:31:57 wiz Exp $
#

DISTNAME=	pcb-${SNAPDATE}
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcb/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://pcb.sourceforge.net/
COMMENT=	Printed circuit board layout system

DEPENDS+=	tk>=8.3:../../x11/tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	pcb-current-[0-9]*

SNAPDATE=		20050609
GNU_CONFIGURE=		yes
USE_TOOLS+=		bison gm4:run gmake lex

# needed for XWarpPointer in action.c
LIBS+=		-lX11

INFO_FILES=	pcb.info

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=   TKDIR=tk
CONFIGURE_ENV+=	WISH=${TKDIR}/bin/wish

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
