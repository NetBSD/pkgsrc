# $NetBSD: Makefile,v 1.42 2008/04/10 21:19:19 jlam Exp $

DISTNAME=	mtools-3.9.11
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://mtools.linux.lu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://mtools.linux.lu/
COMMENT=	FAT (MS-DOS, Atari) disk access tools

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	 *-*-alpha *-*-sparc64	# LP64 problem

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
