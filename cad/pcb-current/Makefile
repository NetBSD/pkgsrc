# $NetBSD: Makefile,v 1.6 2004/04/27 21:02:42 dmcmahill Exp $
#

DISTNAME=	pcb-${SNAPDATE}
PKGNAME=	pcb-current-${SNAPDATE}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcb/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://pcb.sourceforge.net/
COMMENT=	Printed circuit board layout system (development snapshot version)

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	m4>=1.4:../../devel/m4
DEPENDS+=	tk>=8.3:../../x11/tk83

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	pcb-[0-9]*

SNAPDATE=	20040215
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	lex make
USE_X11=	yes
USE_BUILDLINK3=	yes

EVAL_PREFIX+=   BISONDIR=bison
YACC=		${BISONDIR}/bin/bison

INFO_FILES=	pcb.info

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=   TKDIR=tk
EVAL_PREFIX+=   M4DIR=m4
M4=${M4DIR}/bin/${GNU_PROGRAM_PREFIX}m4
CONFIGURE_ENV+=	WISH=${TKDIR}/bin/wish

.include "../../mk/bsd.pkg.mk"
