# $NetBSD: Makefile,v 1.29 2004/02/27 15:28:20 wiz Exp $
#

DISTNAME=	unrarsrc-3.3.6
PKGNAME=	${DISTNAME:S/src//}
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.rarlab.com/
COMMENT=	Extract, view & test RAR archives

USE_GCC_SHLIB=	# defined

MAKEFILE=	makefile.unix

LICENSE=	unrar-license
RESTRICTED=	"Do not modify. Do not charge a fee for redistribution."
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

WRKSRC=		${WRKDIR}/unrar

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unrar
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unrar ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} readme.txt license.txt	\
		${PREFIX}/share/doc/unrar

.include "../../mk/bsd.prefs.mk"

# Don't set _LARGEFILE_SOURCE for platforms w/o ftello() and fseeko().
#
.for __glob__ in NetBSD-1.5*
.if ${MACHINE_PLATFORM:M${__glob__}} != ""
.MAKEFLAGS+=	DEFINES=""
.endif
.endfor

.include "../../mk/bsd.pkg.mk"
