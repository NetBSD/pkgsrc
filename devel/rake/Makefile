# $NetBSD: Makefile,v 1.9 2008/04/04 15:30:00 jlam Exp $

DISTNAME=	rake-0.8.1
PKGREVISION=	1
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
