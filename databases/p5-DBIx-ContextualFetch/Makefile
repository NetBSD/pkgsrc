# $NetBSD: Makefile,v 1.2 2004/11/12 17:36:40 seb Exp $
#

DISTNAME=		DBIx-ContextualFetch-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dbc
CATEGORIES=		perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/DBIx-ContextualFetch/
COMMENT=		Perl5 module adding contextual fetches to DBI

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBIx/ContextualFetch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
