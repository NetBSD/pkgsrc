# $NetBSD: Makefile,v 1.3 2004/02/15 21:57:14 dmcmahill Exp $
#

DISTNAME=	pcb-${SNAPDATE}
PKGNAME=	pcb-current-${SNAPDATE}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcb/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://pcb.sourceforge.net/
COMMENT=	Printed circuit board layout system (development snapshot version)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	m4>=1.4:../../devel/m4
DEPENDS+=	tk>=8.3:../../x11/tk

CONFLICTS+=	pcb-[0-9]*

SNAPDATE=	20030815
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
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
