# $NetBSD: Makefile,v 1.11 2000/09/13 18:03:30 fredb Exp $
# FreeBSD ID: Makefile,v 1.8 1997/01/06 12:04:12 jkh Exp
#

DISTNAME=	nas-1.4.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=audio/nas/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://radscan.com/nas.html

USE_IMAKE=	# defined
USE_X11BASE=	# defined

WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	${PKGDIR}/PLIST.clients
.if ${MACHINE_ARCH} == "i386"
PLIST_SRC+=	${PKGDIR}/PLIST.voxware
.endif

.include "../../mk/bsd.pkg.mk"
