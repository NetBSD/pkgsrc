# $NetBSD: Makefile,v 1.13 2023/12/30 12:15:44 zafer Exp $

DISTNAME=	same-1.8
CATEGORIES=	sysutils
MASTER_SITES=	https://www.aydogan.net/distfiles/sysutils/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bitwizard.nl/
COMMENT=	Find identical files and link(2) them to save disk space

AUTO_MKDIRS=		yes
USE_BSD_MAKEFILE=	yes

post-extract:
	cd ${FILESDIR} && cp -f Makefile same.1 same.cat1 ${WRKSRC}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
