# $NetBSD: Makefile,v 1.15 2019/06/30 20:16:07 nia Exp $

DISTNAME=	Padre-Plugin-Kate-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	editors perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Padre-Plugin-Kate
COMMENT=	Padre plugin using the Kate syntax highlighter
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Padre>=0.65:../../editors/p5-Padre
DEPENDS+=	p5-Syntax-Highlight-Engine-Kate>=0.05:../../textproc/p5-Syntax-Highlight-Engine-Kate

PERL5_PACKLIST=		auto/Padre/Plugin/Kate/.packlist
PERL5_MODULE_TYPE=	Module::Build

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
