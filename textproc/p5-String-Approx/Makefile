# $NetBSD: Makefile,v 1.4 2005/04/11 21:47:38 tv Exp $
#

DISTNAME=		String-Approx-3.23
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://search.cpan.org/dist/String-Approx/
COMMENT=		Approximate (fuzzy) string matching library for Perl

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/String/Approx/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
