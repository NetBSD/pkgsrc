# $NetBSD: Makefile,v 1.7 2020/08/31 18:07:05 wiz Exp $

DISTNAME=	Net-FileMaker-0.064
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	databases perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/S/SQ/SQUEEK/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/S/SQ/SQUEEK/
COMMENT=	Perl Module to interact with FileMaker services
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-XML-Twig-[0-9]*:../../textproc/p5-XML-Twig
BUILD_DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
BUILD_DEPENDS+=	p5-DateTime-Format-CLDR-[0-9]*:../../time/p5-DateTime-Format-CLDR

PERL5_PACKLIST=	auto/Net/FileMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
