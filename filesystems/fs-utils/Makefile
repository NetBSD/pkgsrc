# $NetBSD: Makefile,v 1.3 2008/11/24 16:28:31 stacktic Exp $
#

DISTNAME=	fs-utils_20081124
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	filesystems
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/stacktic/

MAINTAINER=	stacktic@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/~stacktic/fs-utils.html
COMMENT=	Tools to access/modify a file system image through RUMP

ONLY_FOR_PLATFORM= NetBSD-4.99.7[2-9]-* NetBSD-[5-9]*

MAKE_ENV+=	MKLINT=no
MAKE_ENV+=	MKHTML=no

.include "../../mk/bsd.pkg.mk"
