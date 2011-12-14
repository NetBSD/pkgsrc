# $NetBSD: Makefile,v 1.1.1.1 2011/12/14 16:57:37 taca Exp $

DISTNAME=	unf-0.0.4
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/knu/unf
COMMENT=	Wrapper library to bring Unicode Normalization Form support
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-unf_ext>=0.0.3:../../converters/ruby-unf_ext

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
