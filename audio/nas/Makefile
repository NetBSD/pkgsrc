# $NetBSD: Makefile,v 1.16 2002/06/09 20:21:08 tron Exp $
# FreeBSD ID: Makefile,v 1.8 1997/01/06 12:04:12 jkh Exp
#

DISTNAME=	nas-1.4.2.src
PKGNAME=	${DISTNAME:S/.src//}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	audio
MASTER_SITES=	http://radscan.com/nas/ \
		ftp://ftp.uni-duisburg.de/Sound/NAS/ \

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://radscan.com/nas.html
COMMENT=	Network Audio System

USE_IMAKE=		# defined
USE_X11BASE=		# defined

PLIST_SRC=	${PKGDIR}/PLIST.clients
.if ${MACHINE_ARCH} == "i386"
PLIST_SRC+=	${PKGDIR}/PLIST.voxware
.endif

.include "../../mk/bsd.pkg.mk"
