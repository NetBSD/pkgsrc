# $NetBSD: Makefile,v 1.2 2002/10/21 14:43:25 wiz Exp $

DISTNAME=	wavesurfer-1.4.3
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.kth.se/wavesurfer/

MAINTAINER=	gson@netbsd.org
HOMEPAGE=	http://www.speech.kth.se/wavesurfer/
COMMENT=	Tool for sound visualization and manipulation

USE_BUILDLINK2=		YES
NO_BUILD=		YES
DIST_SUBDIR=		${PKGNAME}

do-install:
	${CP} ${WRKSRC}/wavesurfer.tcl ${PREFIX}/bin/wavesurfer
	${CP} -R ${WRKSRC}/wsurf1.4 ${PREFIX}/lib/

.include "../../audio/tcl-snack/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
