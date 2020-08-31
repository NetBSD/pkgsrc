# $NetBSD: Makefile,v 1.31 2020/08/31 18:10:38 wiz Exp $
#

DISTNAME=	DNS-ZoneParse-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DNS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DNS-ZoneParse
COMMENT=	Perl5 module for parsing DNS zone files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/DNS/ZoneParse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
