# $NetBSD: Makefile,v 1.1.1.1 2005/08/22 13:48:43 rpaulo Exp $

DISTNAME=	vorbisgain-0.37
CATEGORIES=	audio
MASTER_SITES=	http://sjeng.org/ftp/vorbis/

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=	http://sjeng.org/vorbisgain.html
COMMENT=	ReplayGain technology for Vorbis

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
