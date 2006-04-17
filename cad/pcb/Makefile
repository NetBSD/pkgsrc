# $NetBSD: Makefile,v 1.33 2006/04/17 13:46:18 wiz Exp $
#

DISTNAME=	pcb-${SNAPDATE}
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcb/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://pcb.sourceforge.net/
COMMENT=	Printed circuit board layout system

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	pcb-current-[0-9]*

SNAPDATE=		20060321
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		WISH=${TOOLS_PATH.wish}
USE_TOOLS+=		bison gm4:run gmake lex wish:run
INFO_FILES=		# PLIST

# needed for XWarpPointer in action.c
LIBS+=		-lX11

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
