# $NetBSD: Makefile,v 1.26.6.1 2003/06/19 01:10:19 grant Exp $
#

DISTNAME=	mtools-3.9.7
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/knaff/mtools/

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www.tux.org/pub/knaff/mtools/
COMMENT=	FAT (MS-DOS, Atari) disk access tools

NOT_FOR_PLATFORM = *-*-alpha *-*-sparc64	# LP64 problem

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
INFO_FILES=	mtools.info

TEXINFO_OVERRIDE=	YES

.include "../../mk/bsd.prefs.mk"

.if defined(MTOOLS_ENABLE_FLOPPYD) && !empty(MTOOLS_ENABLE_FLOPPYD:M[Yy][Ee][Ss])
USE_X11=	YES
CPPFLAGS=	-I${X11BASE}/include
CONFIGURE_ARGS=	--enable-floppyd
PLIST_SUBST=	NOFLOPPYD=
.else
CONFIGURE_ARGS=	--disable-floppyd
PLIST_SUBST=	NOFLOPPYD="@comment "
.endif

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
