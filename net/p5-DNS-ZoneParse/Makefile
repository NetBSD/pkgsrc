# $NetBSD: Makefile,v 1.1.1.1 2002/10/15 15:36:46 cjep Exp $
#

DISTNAME=	DNS-ZoneParse-0.82
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dzp
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DNS/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://search.cpan.org/author/SIMONFLK/DNS-ZoneParse-0.82/ZoneParse.pm
COMMENT=	Perl5 module for parsing DNS zone files

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DNS/ZoneParse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
