# $NetBSD: Makefile,v 1.5 2000/12/05 22:35:09 perry Exp $
#

DISTNAME=		libcdaudio-0.99.4
CATEGORIES=		audio
MASTER_SITES=		ftp://cdcd.undergrid.net/libcdaudio/ \
			http://cdcd.undergrid.net/libcdaudio/source_archive/ \
			ftp://gjhsnews.mesa.k12.co.us/pub/libcdaudio/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://cdcd.undergrid.net/libcdaudio/

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
