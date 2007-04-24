# $NetBSD: Makefile,v 1.1.1.1 2007/04/24 19:06:03 agc Exp $
#

DISTNAME=	u9fs-2.0.3
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=v9fs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://plan9.bell-labs.com/
COMMENT=	Unix file server using the 9P protocol

WRKSRC=		${WRKDIR}/u9fs

MAKE_FILE=	makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/u9fs.8 ${PREFIX}/${PKGMANDIR}/man8/

.include "../../mk/bsd.pkg.mk"
