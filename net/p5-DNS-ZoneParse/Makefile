# $NetBSD: Makefile,v 1.9 2005/07/13 18:01:34 jlam Exp $
#

DISTNAME=	DNS-ZoneParse-0.95
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dzp
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DNS/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DNS-ZoneParse/
COMMENT=	Perl5 module for parsing DNS zone files

PERL5_PACKLIST=	auto/DNS/ZoneParse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
