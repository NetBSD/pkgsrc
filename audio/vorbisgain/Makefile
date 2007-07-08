# $NetBSD: Makefile,v 1.3 2007/07/08 12:35:10 wiz Exp $

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
