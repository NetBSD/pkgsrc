# $NetBSD: Makefile,v 1.30 2005/05/31 16:13:18 wiz Exp $

DISTNAME=	libsndfile-1.0.11
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/libsndfile/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mega-nerd.com/libsndfile/
COMMENT=	Library for reading and writing audio files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	sndfile.pc.in

# This package compiles with gcc2, but its configure script doesn't know that
CONFIGURE_ENV+=		ac_cv_c_struct_hack=yes
# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
BUILDLINK_PASSTHRU_DIRS+=	/Developer
.endif

.include "../../mk/bsd.pkg.mk"
