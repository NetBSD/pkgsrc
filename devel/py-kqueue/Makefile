# $NetBSD: Makefile,v 1.1.1.1 2002/11/24 09:30:24 jdolecek Exp $

DISTNAME=	py-kqueue-2.0
PKGNAME=	${PYPKGPREFIX}-kqueue-2.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/jdolecek/

MAINTAINER=	jdolecek@netbsd.org
COMMENT=	Python interface to kqueue(2) and kevent(2) system calls

PYDISTUTILSPKG= # defined

# need to get definition of PKG_HAVE_KQUEUE
.include "../../mk/bsd.prefs.mk"

.if !defined(PKG_HAVE_KQUEUE)
IGNORE+=	"${PKGNAME} is not available for ${MACHINE_PLATFORM}, needs OS support for kqueue(2)"
.endif

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
