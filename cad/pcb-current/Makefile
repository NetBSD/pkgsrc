# $NetBSD: Makefile,v 1.11 2004/10/03 00:13:13 tv Exp $
#

DISTNAME=	pcb-${SNAPDATE}
PKGNAME=	pcb-current-${SNAPDATE}
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcb/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://pcb.sourceforge.net/
COMMENT=	Printed circuit board layout system (development snapshot version)

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	m4>=1.4:../../devel/m4
DEPENDS+=	tk>=8.3:../../x11/tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	pcb-[0-9]*

SNAPDATE=	20040903
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	lex make
USE_X11=	yes
USE_BUILDLINK3=	yes

INFO_FILES=	pcb.info

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=   BISONDIR=bison
EVAL_PREFIX+=   M4DIR=m4
EVAL_PREFIX+=   TKDIR=tk
M4=${M4DIR}/bin/${GNU_PROGRAM_PREFIX}m4
YACC=		${BISONDIR}/bin/bison
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
