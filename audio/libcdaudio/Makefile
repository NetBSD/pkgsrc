# $NetBSD: Makefile,v 1.4 2000/08/14 13:41:00 wiz Exp $
#

DISTNAME=		libcdaudio-0.99.1
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
