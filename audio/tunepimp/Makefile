# $NetBSD: Makefile,v 1.4 2004/11/01 12:47:22 markd Exp $

DISTNAME=	libtunepimp-0.3.0
PKGNAME=	${DISTNAME:S/lib//}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.musicbrainz.org/
COMMENT=	Create MusicBrainz enabled tagging applications

CONFLICTS=	trm-[0-9]*

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
pre-configure:
	${ECHO} "#define HAVE_STATVFS 1" >> ${WRKSRC}/config.h.in
.endif

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
