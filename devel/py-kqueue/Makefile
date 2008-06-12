# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:28 joerg Exp $

DISTNAME=	py-kqueue-2.0
PKGNAME=	${PYPKGPREFIX}-kqueue-2.0
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/jdolecek/

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	Python interface to kqueue(2) and kevent(2) system calls

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= # defined

# need to get definition of PKG_HAVE_KQUEUE
.include "../../mk/bsd.prefs.mk"

.if !defined(PKG_HAVE_KQUEUE)
PKG_SKIP_REASON+= "${PKGNAME} is not available for ${MACHINE_PLATFORM}, needs OS support for kqueue(2)"
.endif

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
