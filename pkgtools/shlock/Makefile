# $NetBSD: Makefile,v 1.24 2012/04/23 03:41:28 mspo Exp $
#

DISTNAME=	shlock-20080529
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Shell utility to perform dot-locking

PKG_DESTDIR_SUPPORT=	user-destdir
USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1
PKGSRC_LOCKTYPE=	none	# avoid "bootstrapping problem"

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
