# $NetBSD: Makefile,v 1.43.2.1 2008/01/29 14:05:51 ghen Exp $

DISTNAME=	libsndfile-1.0.17
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/libsndfile/

PATCHFILES=	libsndfile-1.0.17+flac-1.1.3.patch.bz2
PATCH_SITES=	${MASTER_SITE_GENTOO:=distfiles/}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mega-nerd.com/libsndfile/
COMMENT=	Library for reading and writing audio files

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	sndfile.pc.in
GNU_CONFIGURE=		yes

MAKE_JOBS_SAFE=		no

# This package compiles with gcc2, but its configure script doesn't know that
CONFIGURE_ENV+=		ac_cv_c_struct_hack=yes
# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
BUILDLINK_PASSTHRU_DIRS+=	/Developer
.endif

.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
