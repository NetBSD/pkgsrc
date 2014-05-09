# $NetBSD: Makefile,v 1.14 2014/05/09 07:37:01 wiz Exp $

DISTNAME=	py-kqueue-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/jdolecek/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python interface to kqueue(2) and kevent(2) system calls
LICENSE=	modified-bsd

# need to get definition of PKG_HAVE_KQUEUE
.include "../../mk/bsd.prefs.mk"

.if !defined(PKG_HAVE_KQUEUE)
PKG_FAIL_REASON+= "${PKGNAME} is not available for ${MACHINE_PLATFORM}, needs OS support for kqueue(2)"
.endif

EGG_NAME=	${DISTNAME:S/py-//}
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 2.0

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
