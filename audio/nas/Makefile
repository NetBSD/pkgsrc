# $NetBSD: Makefile,v 1.15 2001/08/22 17:38:56 jlam Exp $
# FreeBSD ID: Makefile,v 1.8 1997/01/06 12:04:12 jkh Exp
#

DISTNAME=	nas-1.4.2.src
PKGNAME=	${DISTNAME:S/.src//}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	audio
MASTER_SITES=	http://radscan.com/nas/ \
		${MASTER_SITE_XCONTRIB:=audio/nas/}

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
