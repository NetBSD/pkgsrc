# $NetBSD: Makefile,v 1.3 2007/01/10 22:48:56 bad Exp $
#

DISTNAME=	List-MoreUtils-0.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/V/VP/VPARSEVAL/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/dist/List-MoreUtils/
COMMENT=	Provide the stuff missing in List::Util

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/List/MoreUtils/.packlist

# avoid trying to build the XS version.
MAKE_PARAMS.makemaker+= -pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
