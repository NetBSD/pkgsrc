# $NetBSD: Makefile,v 1.1.1.1 2008/09/10 11:03:21 joerg Exp $
#

DISTNAME=	nbpatch-20080910
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Patch files using diff output

PKG_DESTDIR_SUPPORT=	user-destdir

# Allow checkperms and othher core dependencies to use patches
CHECK_PERMS=		no

USE_BSD_MAKEFILE=	yes
USE_FEATURES=		nbcompat

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
