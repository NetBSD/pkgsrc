# $NetBSD: Makefile,v 1.1.1.1 2004/04/17 13:21:48 minskim Exp $

DISTNAME=	same-1.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.bitwizard.nl/same/

MAINTAINER=	roland.illig@gmx.de
HOMEPAGE=	http://www.bitwizard.nl/
COMMENT=	Find identical files and link(2) them to save disk space

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKEFILE=	${FILESDIR}/Makefile

INSTALLATION_DIRS=	bin man/man1

post-patch:
	@${CP} ${FILESDIR}/same.1 ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
