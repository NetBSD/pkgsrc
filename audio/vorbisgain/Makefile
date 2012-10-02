# $NetBSD: Makefile,v 1.5 2012/10/02 23:48:12 asau Exp $

DISTNAME=	vorbisgain-0.37
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://sjeng.org/ftp/vorbis/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sjeng.org/vorbisgain.html
COMMENT=	ReplayGain technology for Vorbis

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
