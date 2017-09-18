# $NetBSD: Makefile,v 1.11 2017/09/18 03:42:14 taca Exp $

DISTNAME=	hiera-3.4.1
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
