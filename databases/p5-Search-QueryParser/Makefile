# $NetBSD: Makefile,v 1.1.1.1 2008/10/12 21:49:33 he Exp $

DISTNAME=	Search-QueryParser-0.93
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Search/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Search-QueryParser/
COMMENT=	Parses a query string into a data suitable for search engines

PERL5_PACKLIST=	auto/Search/QueryParser/.packlist

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
