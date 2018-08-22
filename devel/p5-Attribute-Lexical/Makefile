# $NetBSD: Makefile,v 1.15 2018/08/22 09:43:37 wiz Exp $

DISTNAME=	Attribute-Lexical-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Attribute/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Attribute-Lexical/
COMMENT=	Sane scoping of function/variable attributes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Lexical-SealRequireHints>=0.005:../../devel/p5-Lexical-SealRequireHints
DEPENDS+=	p5-Params-Classify-[0-9]*:../../devel/p5-Params-Classify

USE_LANGUAGES=		# none

PERL5_PACKLIST=		auto/Attribute/Lexical/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
