# $NetBSD: Makefile,v 1.43 2010/01/07 07:36:54 wiz Exp $

DISTNAME=	mtools-3.9.11
PKGREVISION=	1
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
