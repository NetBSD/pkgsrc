# $NetBSD: Makefile,v 1.18 2022/06/28 11:36:28 wiz Exp $
#

DISTNAME=	Template-Plugin-CSV-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Template-Plugin-CSV
COMMENT=	Template::Toolkit plugin for generating CSV
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Template-Toolkit>=2:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-CSV-[0-9]*:../../textproc/p5-Text-CSV

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Template/Plugin/CSV/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
