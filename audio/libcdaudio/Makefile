# $NetBSD: Makefile,v 1.6 2001/02/16 13:30:45 wiz Exp $
#

DISTNAME=		libcdaudio-0.99.4
CATEGORIES=		audio
MASTER_SITES=		ftp://cdcd.undergrid.net/libcdaudio/ \
			http://cdcd.undergrid.net/libcdaudio/source_archive/ \
			ftp://gjhsnews.mesa.k12.co.us/pub/libcdaudio/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://cdcd.undergrid.net/libcdaudio/
COMMENT=		Multi-platform CD player development library

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
