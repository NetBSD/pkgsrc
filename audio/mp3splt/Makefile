# $NetBSD: Makefile,v 1.11 2006/08/10 16:16:13 wiz Exp $
#

DISTNAME=		mp3splt-2.1c-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mp3splt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mp3splt.sourceforge.net/
COMMENT=		Command line utility to split MP3 (VBR supported) and OGG files

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
