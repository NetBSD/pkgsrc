# $NetBSD: Makefile,v 1.7 2006/06/02 17:29:30 joerg Exp $

DISTNAME=	py-kqueue-2.0
PKGNAME=	${PYPKGPREFIX}-kqueue-2.0
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/jdolecek/

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	Python interface to kqueue(2) and kevent(2) system calls

PYDISTUTILSPKG= # defined
PYTHON_VERSIONS_ACCEPTED= 24 23 22

# need to get definition of PKG_HAVE_KQUEUE
.include "../../mk/bsd.prefs.mk"

.if !defined(PKG_HAVE_KQUEUE)
PKG_SKIP_REASON+= "${PKGNAME} is not available for ${MACHINE_PLATFORM}, needs OS support for kqueue(2)"
.endif

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
