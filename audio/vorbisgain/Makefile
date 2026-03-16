# $NetBSD: Makefile,v 1.9 2026/03/16 12:17:18 nia Exp $

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

TOOL_DEPENDS+=	dos2unix-[0-9]*:../../converters/dos2unix

pre-patch:
	find ${WRKSRC} -name "*.c" -type f | xargs dos2unix
	find ${WRKSRC} -name "*.h" -type f | xargs dos2unix

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
