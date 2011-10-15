# $NetBSD: Makefile,v 1.10 2011/10/15 08:23:55 obache Exp $

DISTNAME=	py-kqueue-2.0
PKGNAME=	${PYPKGPREFIX}-kqueue-2.0
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/jdolecek/

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	Python interface to kqueue(2) and kevent(2) system calls
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

# need to get definition of PKG_HAVE_KQUEUE
.include "../../mk/bsd.prefs.mk"

.if !defined(PKG_HAVE_KQUEUE)
PKG_FAIL_REASON+= "${PKGNAME} is not available for ${MACHINE_PLATFORM}, needs OS support for kqueue(2)"
.endif

EGG_NAME=	${DISTNAME:S/py-//}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
