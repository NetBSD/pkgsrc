# $NetBSD: Makefile,v 1.4 2004/04/11 17:31:12 xtraeme Exp $
#

DISTNAME=		mp3splt-1.9-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=				1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mp3splt/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://mp3splt.sourceforge.net/
COMMENT=		Command line utility to split MP3 (VBR supported) and OGG files

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
