# $NetBSD: Makefile,v 1.11 2019/11/04 21:28:52 rillig Exp $

DISTNAME=	same-1.8
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.bitwizard.nl/same/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/
COMMENT=	Find identical files and link(2) them to save disk space

AUTO_MKDIRS=		yes
USE_BSD_MAKEFILE=	yes

post-extract:
	cd ${FILESDIR} && cp -f Makefile same.1 same.cat1 ${WRKSRC}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
