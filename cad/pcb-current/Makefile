# $NetBSD: Makefile,v 1.18 2005/07/15 20:14:03 jlam Exp $
#

DISTNAME=	pcb-${SNAPDATE}
PKGNAME=	pcb-current-${SNAPDATE}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcb/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://pcb.sourceforge.net/
COMMENT=	Printed circuit board layout system (development snapshot version)

DEPENDS+=	tk>=8.3:../../x11/tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	pcb-[0-9]*

SNAPDATE=		20050315
GNU_CONFIGURE=		yes
USE_TOOLS+=		bison gm4:run gmake lex

INFO_FILES=	pcb.info

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=   TKDIR=tk
CONFIGURE_ENV+=	WISH=${TKDIR}/bin/wish

.if ${XAW_TYPE} == "xpm"
CONFIGURE_ARGS+=	--with-xaw=Xaw-Xpm
.elif ${XAW_TYPE} == "3d"
CONFIGURE_ARGS+=	--with-xaw=Xaw3d
.elif ${XAW_TYPE} == "neXtaw"
CONFIGURE_ARGS+=	--with-xaw=neXtaw
.else
CONFIGURE_ARGS+=	--with-xaw=Xaw
.endif

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
