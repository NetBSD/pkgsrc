# $NetBSD: Makefile,v 1.41 2005/12/12 21:36:54 joerg Exp $
#

DISTNAME=		snd-7.15
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=snd/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ccrma.stanford.edu/software/snd/
COMMENT=		X based sound editor

DEPENDS+=		flac-[0-9]*:../../audio/flac
DEPENDS+=		speex-[0-9]*:../../audio/speex
DEPENDS+=		vorbis-tools-[0-9]*:../../audio/vorbis-tools

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

BUILD_TARGET=		snd
MAKEFILE=		makefile
WRKSRC=			${WRKDIR}/snd-7

post-install:
	${INSTALL_DATA} ${WRKSRC}/po/de.gmo \
		${PREFIX}/${PKGLOCALEDIR}/locale/de/LC_MESSAGES/snd.mo

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
