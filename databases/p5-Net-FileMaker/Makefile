# $NetBSD: Makefile,v 1.10 2021/05/24 19:49:40 wiz Exp $

DISTNAME=	Net-FileMaker-0.064
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SQ/SQUEEK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Net::FileMaker
COMMENT=	Perl Module to interact with FileMaker services
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-XML-Twig-[0-9]*:../../textproc/p5-XML-Twig
BUILD_DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
BUILD_DEPENDS+=	p5-DateTime-Format-CLDR-[0-9]*:../../time/p5-DateTime-Format-CLDR

PERL5_PACKLIST=	auto/Net/FileMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
