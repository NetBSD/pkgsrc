# $NetBSD: Makefile,v 1.8 2009/05/19 08:59:26 wiz Exp $
#

DISTNAME=	fetch-1.5
CATEGORIES=	net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.FreeBSD.org/
COMMENT=	Client to fetch URLs
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_FEATURES=		nbcompat

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
