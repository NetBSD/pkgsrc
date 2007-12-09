# $NetBSD: Makefile,v 1.41 2007/12/09 23:38:21 wiz Exp $

DISTNAME=	mtools-3.9.11
CATEGORIES=	sysutils
MASTER_SITES=	http://mtools.linux.lu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://mtools.linux.lu/
COMMENT=	FAT (MS-DOS, Atari) disk access tools

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM = *-*-alpha *-*-sparc64	# LP64 problem

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		YES

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
