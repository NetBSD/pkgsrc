# $NetBSD: Makefile,v 1.5 2000/11/11 17:49:23 tron Exp $
#

DISTNAME=	mad-0.11.4b
PKGNAME=	madplay-0.11.4b
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/}

MAINTAINER=	simonb@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/mad/

GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386")
CONFIGURE_ARGS+=	--enable-fpm=i386
.elif (${MACHINE_ARCH} == "sparc")
CONFIGURE_ARGS+=	--enable-fpm=sparc
.elif (${MACHINE_ARCH} == "arm32")
CONFIGURE_ARGS+=	--enable-fpm=arm
.endif

.include "../../mk/bsd.pkg.mk"
