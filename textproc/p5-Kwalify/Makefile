# $NetBSD: Makefile,v 1.17 2019/08/11 13:23:29 wiz Exp $

DISTNAME=	Kwalify-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SR/SREZIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Kwalify
COMMENT=	Perl implementation of Kwalify parser, validator and data binding tool
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Kwalify/.packlist

# For test really
BUILD_DEPENDS+=	p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
