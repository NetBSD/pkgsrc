# $NetBSD: Makefile,v 1.1.1.1 2004/11/06 01:27:29 he Exp $
#

DISTNAME=		DBIx-ContextualFetch-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dbc
CATEGORIES=		perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~tmtm/DBIx-ContextualFetch-1.01/
COMMENT=		Perl5 module adding contextual fetches to DBI

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBIx/ContextualFetch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
