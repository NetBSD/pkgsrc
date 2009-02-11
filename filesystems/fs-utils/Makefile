# $NetBSD: Makefile,v 1.5 2009/02/11 22:04:40 stacktic Exp $
#

DISTNAME=	fs-utils_20090211
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	filesystems
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/stacktic/

MAINTAINER=	stacktic@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/~stacktic/fs-utils.html
COMMENT=	Tools to access/modify a file system image through RUMP

ONLY_FOR_PLATFORM= NetBSD-4.99.7[2-9]-* NetBSD-[5-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
