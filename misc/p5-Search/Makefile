# $NetBSD: Makefile,v 1.15 2004/04/27 02:24:09 snj Exp $
# FreeBSD Id: Makefile,v 1.9 1997/06/24 18:43:31 jfitz Exp
#

DISTNAME=		Search-0.2
PKGNAME=		p5-Search-0.2
SVR4_PKGNAME=		p5sea
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Search/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module to provide framework for multiple searches

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Search/Text/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
