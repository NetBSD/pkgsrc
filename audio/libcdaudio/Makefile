# $NetBSD: Makefile,v 1.8 2001/11/26 05:56:36 jlam Exp $
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

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
