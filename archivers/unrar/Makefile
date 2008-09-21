# $NetBSD: Makefile,v 1.58 2008/09/21 10:45:34 wiz Exp $

DISTNAME=	unrarsrc-3.7.8
PKGNAME=	${DISTNAME:S/src//}
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/ \
		ftp://ftp.rarlab.com/rar/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.rarlab.com/
COMMENT=	Extract, view & test RAR archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	YES
USE_LANGUAGES=	c++

MAKE_FILE=	makefile.unix

LICENSE=	unrar-license
RESTRICTED=	Do not charge a fee for redistribution.  Do not use to develop a rar archiver.
# Reading the license implies NO_BIN_ON_FTP should be set because no
# permission is granted to distribute derived works (e.g., binaries).
# From private mail addressed to pkgsrc maintainers:
#
# Date: Wed, 10 Sep 2008 18:27:35 +0600
# From: Eugene Roshal <roshal@rarlab.com>
# You can redistribute either original or modified binaries or sources.
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

WRKSRC=		${WRKDIR}/unrar

INSTALLATION_DIRS=	bin share/doc/unrar

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} readme.txt license.txt	\
		${DESTDIR}${PREFIX}/share/doc/unrar

.include "../../mk/bsd.prefs.mk"

# Don't set _LARGEFILE_SOURCE for platforms w/o ftello() and fseeko().
#
.for platform in Interix-* NetBSD-1.5*
.  if ${MACHINE_PLATFORM:M${platform}} != ""
.MAKEFLAGS+=	DEFINES=""
.  endif
.endfor

.include "../../mk/bsd.pkg.mk"
