# $NetBSD: Makefile,v 1.40 2007/08/17 20:55:34 joerg Exp $

DISTNAME=	mtools-3.9.10
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tux.org/pub/knaff/mtools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://www.tux.org/pub/knaff/mtools/
COMMENT=	FAT (MS-DOS, Atari) disk access tools

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM = *-*-alpha *-*-sparc64	# LP64 problem

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		# PLIST

.include "../../mk/bsd.prefs.mk"

.if defined(MTOOLS_ENABLE_FLOPPYD) && !empty(MTOOLS_ENABLE_FLOPPYD:M[Yy][Ee][Ss])
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
CPPFLAGS+=		-I${X11BASE}/include
CONFIGURE_ARGS+=	--enable-floppyd
PLIST_SUBST+=		NOFLOPPYD=
.else
CONFIGURE_ARGS+=	--disable-floppyd
PLIST_SUBST+=		NOFLOPPYD="@comment "
.endif

.include "../../mk/bsd.pkg.mk"
