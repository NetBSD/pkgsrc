# $NetBSD: Makefile,v 1.39 2005/09/05 00:44:49 wiz Exp $

DISTNAME=	unrarsrc-3.5.3
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

MAKEFILE=	makefile.unix

LICENSE=	unrar-license
RESTRICTED=	"Do not modify. Do not charge a fee for redistribution."
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

WRKSRC=		${WRKDIR}/unrar

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unrar
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unrar ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} readme.txt license.txt	\
		${PREFIX}/share/doc/unrar

.include "../../mk/bsd.prefs.mk"

# Don't set _LARGEFILE_SOURCE for platforms w/o ftello() and fseeko().
#
.for __glob__ in Interix-* NetBSD-1.5*
.  if ${MACHINE_PLATFORM:M${__glob__}} != ""
.MAKEFLAGS+=	DEFINES=""
.  endif
.endfor

.include "../../mk/bsd.pkg.mk"
