# $NetBSD: Makefile,v 1.44 2010/04/19 13:44:48 is Exp $

DISTNAME=	mtools-4.0.13
PKGREVISION=	#
CATEGORIES=	sysutils
MASTER_SITES=	http://mtools.linux.lu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://mtools.linux.lu/
COMMENT=	FAT (MS-DOS, Atari) disk access tools

PKG_DESTDIR_SUPPORT=	user-destdir

# LP64 problem
NOT_FOR_PLATFORM=	 ${LP64PLATFORMS}

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
