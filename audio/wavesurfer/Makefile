# $NetBSD: Makefile,v 1.1.1.1 2002/08/25 18:50:00 gson Exp $

DISTNAME=	wavesurfer-1.4.3
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.kth.se/wavesurfer/

MAINTAINER=	gson@netbsd.org
HOMEPAGE=	http://www.speech.kth.se/wavesurfer/
COMMENT=	Tool for sound visualization and manipulation

DEPENDS+=	tcl-snack-2.2a2:../tcl-snack

USE_BUILDLINK_ONLY=	YES
NO_BUILD=		YES

do-install:
	${CP} ${WRKSRC}/wavesurfer.tcl ${PREFIX}/bin/wavesurfer
	${CP} -R ${WRKSRC}/wsurf1.4 ${PREFIX}/lib/

.include "../../x11/tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
