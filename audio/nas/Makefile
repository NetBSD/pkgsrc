# $NetBSD: Makefile,v 1.12 2001/02/16 13:30:48 wiz Exp $
# FreeBSD ID: Makefile,v 1.8 1997/01/06 12:04:12 jkh Exp
#

DISTNAME=	nas-1.4.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=audio/nas/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://radscan.com/nas.html
COMMENT=	Network Audio System

USE_IMAKE=	# defined
USE_X11BASE=	# defined

WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	${PKGDIR}/PLIST.clients
.if ${MACHINE_ARCH} == "i386"
PLIST_SRC+=	${PKGDIR}/PLIST.voxware
.endif

.include "../../mk/bsd.pkg.mk"
