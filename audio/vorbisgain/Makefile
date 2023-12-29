# $NetBSD: Makefile,v 1.8 2023/12/29 01:07:34 zafer Exp $

DISTNAME=	vorbisgain-0.37
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://sjeng.org/ftp/vorbis/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sjeng.org/vorbisgain.html
COMMENT=	ReplayGain technology for Vorbis
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
