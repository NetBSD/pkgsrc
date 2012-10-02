# $NetBSD: Makefile,v 1.8 2012/10/02 23:48:00 asau Exp $

DISTNAME=	mpegaudio
PKGNAME=	mpegaudio-3.9
CATEGORIES=	audio
MASTER_SITES=	# empty
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MPEG/audio Layer 1 and Layer 2 encoder/decoder package

INSTALLATION_DIRS+=  bin ${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${FILESDIR}/mpeg_musicin.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${FILESDIR}/mpeg_musicout.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
