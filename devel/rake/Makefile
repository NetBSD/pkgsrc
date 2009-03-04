# $NetBSD: Makefile,v 1.12 2009/03/04 17:39:22 minskim Exp $

DISTNAME=	rake-0.8.4
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rake.rubyforge.org/
COMMENT=	Ruby Make

USE_TOOLS+=	gzip
GEM_BUILD=	gemspec

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-extract:
	cd ${WRKSRC}/doc && gzip -d < rake.1.gz > rake.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/rake.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
