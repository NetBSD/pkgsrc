# $NetBSD: Makefile,v 1.5 2004/04/27 06:05:57 snj Exp $
#

DISTNAME=	DNS-ZoneParse-0.82
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dzp
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DNS/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/author/SIMONFLK/DNS-ZoneParse-0.82/ZoneParse.pm
COMMENT=	Perl5 module for parsing DNS zone files

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DNS/ZoneParse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
