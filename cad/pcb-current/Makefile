# $NetBSD: Makefile,v 1.2 2004/01/22 07:21:55 grant Exp $
#

DISTNAME=	pcb-${SNAPDATE}
PKGNAME=	pcb-current-${SNAPDATE}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcb/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://pcb.sourceforge.net/
COMMENT=	Printed circuit board layout system (development snapshot version)

DEPENDS+=	m4>=1.4:../../devel/m4
DEPENDS+=	tk>=8.3:../../x11/tk

CONFLICTS+=	pcb-[0-9]*

SNAPDATE=	20030815
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

# install to X11BASE until cad/gnetlist is taught to handle pcb installing
# to X11BASE and pcb-current installing to LOCALBASE.  Alternatively, once
# there is a stable release of the "new" pcb which can install to LOCALBASE
# we can let pcb-current go there too.
USE_X11BASE=	yes
YACC=		${LOCALBASE}/bin/bison

INFO_FILES=	pcb.info

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=   TKDIR=tk
EVAL_PREFIX+=   M4DIR=m4
M4=${M4DIR}/bin/${GNU_PROGRAM_PREFIX}m4
CONFIGURE_ENV+=	WISH=${TKDIR}/bin/wish

.include "../../mk/bsd.pkg.mk"
