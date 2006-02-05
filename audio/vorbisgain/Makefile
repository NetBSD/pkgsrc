# $NetBSD: Makefile,v 1.2 2006/02/05 23:08:14 joerg Exp $

DISTNAME=	vorbisgain-0.37
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://sjeng.org/ftp/vorbis/

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=	http://sjeng.org/vorbisgain.html
COMMENT=	ReplayGain technology for Vorbis

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
