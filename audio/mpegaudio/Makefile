# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:38:29 jlam Exp $

DISTNAME=	mpegaudio
PKGNAME=	mpegaudio-3.9
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.ise.fhg.de/pub/graphics/mpeg/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	MPEG/audio Layer 1 and Layer 2 encoder/decoder package

post-install:
	${INSTALL_MAN} ${FILESDIR}/mpeg_musicin.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${FILESDIR}/mpeg_musicout.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
