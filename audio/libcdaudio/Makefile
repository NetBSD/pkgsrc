# $NetBSD: Makefile,v 1.7 2001/04/28 14:43:28 drochner Exp $
#

DISTNAME=		libcdaudio-0.99.4
PKGNAME=		libcdaudio-0.99.4nb1
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
