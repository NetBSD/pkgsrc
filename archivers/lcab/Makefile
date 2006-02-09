# $NetBSD: Makefile,v 1.3 2006/02/09 18:07:57 rillig Exp $
#

DISTNAME=		lcab-1.0b10
CATEGORIES=		archivers
MASTER_SITES=		http://www.geekshop.be/rien/lcab/files/

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://www.geekshop.be/rien/lcab
COMMENT=		Microsoft cabinet (.CAB) file creator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	man/man1

post-install:
	${INSTALL_MAN} ${WRKSRC:Q}/lcab.1 ${PREFIX:Q}/man/man1/lcab.1

.include "../../mk/bsd.pkg.mk"
