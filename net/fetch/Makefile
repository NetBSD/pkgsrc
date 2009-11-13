# $NetBSD: Makefile,v 1.9 2009/11/13 20:52:05 joerg Exp $
#

DISTNAME=	fetch-1.6
CATEGORIES=	net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.FreeBSD.org/
COMMENT=	Client to fetch URLs
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_FEATURES=		nbcompat

GNU_CONFIGURE=		yes
USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
