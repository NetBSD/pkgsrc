# $NetBSD: Makefile,v 1.15 2022/06/28 11:36:16 wiz Exp $
#

DISTNAME=	Lingua-EN-FindNumber-1.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Lingua-EN-FindNumber
COMMENT=	Inflect short English Phrases
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Lingua-EN-Words2Nums-[0-9]*:../../textproc/p5-Lingua-EN-Words2Nums

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Lingua/EN/FindNumber/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
