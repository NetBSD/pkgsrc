# $NetBSD: Makefile,v 1.14 2010/09/07 17:20:24 taca Exp $

DISTNAME=	rake-0.8.7
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rake.rubyforge.org/
COMMENT=	Ruby Make

USE_TOOLS+=	gzip
GEM_BUILD=	gemspec

# rake is bundled Ruby 1.9
RUBY_VERSION_SUPPORTED= 18
INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-extract:
	cd ${WRKSRC}/doc && gzip -d < rake.1.gz > rake.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/rake.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
