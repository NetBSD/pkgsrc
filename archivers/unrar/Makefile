# $NetBSD: Makefile,v 1.49 2006/09/09 02:41:54 obache Exp $

DISTNAME=	unrarsrc-3.6.8
PKGNAME=	${DISTNAME:S/src//}
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/ \
		ftp://ftp.rarlab.com/rar/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.rarlab.com/
COMMENT=	Extract, view & test RAR archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	YES
USE_LANGUAGES=	c++

MAKE_FILE=	makefile.unix

LICENSE=	unrar-license
RESTRICTED=	Do not modify. Do not charge a fee for redistribution.
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

WRKSRC=		${WRKDIR}/unrar

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/unrar
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unrar ${PREFIX:Q}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} readme.txt license.txt	\
		${PREFIX:Q}/share/doc/unrar

.include "../../mk/bsd.prefs.mk"

# Don't set _LARGEFILE_SOURCE for platforms w/o ftello() and fseeko().
#
.for platform in Interix-* NetBSD-1.5*
.  if ${MACHINE_PLATFORM:M${platform}} != ""
.MAKEFLAGS+=	DEFINES=""
.  endif
.endfor

.include "../../mk/bsd.pkg.mk"
