# $NetBSD: Makefile,v 1.5 2003/09/10 20:44:18 jmmv Exp $

DISTNAME=	wavesurfer-1.4.6
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.kth.se/wavesurfer/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.speech.kth.se/wavesurfer/
COMMENT=	Tool for sound visualization and manipulation

USE_BUILDLINK2=		YES
NO_BUILD=		YES

do-install:
	${CP} ${WRKSRC}/wavesurfer.tcl ${PREFIX}/bin/wavesurfer
	${CP} -R ${WRKSRC}/wsurf1.4 ${PREFIX}/lib/

.include "../../audio/tcl-snack/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
