# $NetBSD: Makefile,v 1.1.1.1 2003/09/18 14:05:07 wiz Exp $
#

DISTNAME=		mp3splt-1.9-src
PKGNAME=		${DISTNAME:S/-src//}
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mp3splt/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://mp3splt.sourceforge.net/
COMMENT=		Command line utility to split MP3 (VBR supported) and OGG files

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../audio/libmad/buildlink2.mk"
.include "../../audio/libogg/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
