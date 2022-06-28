# $NetBSD: Makefile,v 1.26 2022/06/28 11:32:35 wiz Exp $
#

DISTNAME=	IO-Prompt-0.997004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	https://metacpan.org/release/IO-Prompt
COMMENT=	Interactively prompt for user input
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Want-[0-9]*:../../devel/p5-Want

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Prompt/.packlist

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
