# $NetBSD: Makefile,v 1.21 2019/12/19 23:50:44 joerg Exp $

DISTNAME=	fetch-1.9
CATEGORIES=	net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://www.FreeBSD.org/
COMMENT=	Client to fetch URLs
LICENSE=	modified-bsd

USE_FEATURES=		nbcompat

GNU_CONFIGURE=		yes
USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"
.if !empty(FETCH_USING:Mfetch)
CHECK_PERMS=		no
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

.include "../../net/libfetch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
