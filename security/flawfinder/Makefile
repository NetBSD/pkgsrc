# $NetBSD: Makefile,v 1.31 2023/08/14 05:25:09 wiz Exp $

DISTNAME=	flawfinder-2.0.19
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	https://www.dwheeler.com/flawfinder/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dwheeler.com/flawfinder/
COMMENT=	Python program to find flaws in C/C++ programs
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/flawfinder.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
