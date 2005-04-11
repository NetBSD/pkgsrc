# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:13 tv Exp $
#

DISTNAME=		DBIx-ContextualFetch-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dbc
PKGREVISION=		1
CATEGORIES=		perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/DBIx-ContextualFetch/
COMMENT=		Perl5 module adding contextual fetches to DBI

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBIx/ContextualFetch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
