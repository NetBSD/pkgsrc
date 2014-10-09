# $NetBSD: Makefile,v 1.10 2014/10/09 14:06:59 wiz Exp $

DISTNAME=	same-1.8
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.bitwizard.nl/same/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/
COMMENT=	Find identical files and link(2) them to save disk space

AUTO_MKDIRS=			yes
USE_BSD_MAKEFILE=	yes

post-extract:
	cd ${FILESDIR} && cp -f Makefile same.1 same.cat1 ${WRKSRC}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
