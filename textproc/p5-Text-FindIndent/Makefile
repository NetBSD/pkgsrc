# $NetBSD: Makefile,v 1.20 2019/08/11 13:23:44 wiz Exp $

DISTNAME=	Text-FindIndent-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-FindIndent
COMMENT=	Heuristically determine the indent style
LICENSE=	${PERL5_LICENSE}

#BUILD_DEPENDS+= {perl>=5.10.1,p5-Test-Simple>=0.80}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Text/FindIndent/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
