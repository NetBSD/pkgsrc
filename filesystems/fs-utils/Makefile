# $NetBSD: Makefile,v 1.2 2008/09/29 16:41:18 stacktic Exp $
#

DISTNAME=	fs-utils_20080929
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	filesystems
MASTER_SITES=	http://www.stacktic.org/

MAINTAINER=	stacktic@NetBSD.org
HOMEPAGE=	http://netbsd-soc.sourceforge.net/projects/fs-utils/
COMMENT=	Tools to access/modify a file system image through RUMP

ONLY_FOR_PLATFORM= NetBSD-4.99.7[2-9]-* NetBSD-4.99.[89][0-9]-* NetBSD-[5-9]*

MAKE_ENV+=	MKLINT=no

.include "../../mk/bsd.pkg.mk"
