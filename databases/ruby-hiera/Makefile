# $NetBSD: Makefile,v 1.9 2017/06/12 15:21:19 taca Exp $

DISTNAME=	hiera-3.3.1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/puppetlabs/hiera/
COMMENT=	Light weight hierarchical data store
LICENSE=	apache-2.0

RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	cd ${WRKSRC} && ${FIND} . -type f -exec ${CHMOD} g-w {} \;
	cd ${WRKSRC}/bin && ${CHMOD} ${BINMODE} hiera

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
