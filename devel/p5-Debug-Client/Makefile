# $NetBSD: Makefile,v 1.25 2023/07/06 09:38:58 wiz Exp $

DISTNAME=	Debug-Client-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Debug/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Debug-Client
COMMENT=	Client side code for perl debugger
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PadWalker>=1.9.2:../../devel/p5-PadWalker
DEPENDS+=	p5-Term-ReadLine-Perl>=1.0303:../../devel/p5-Term-ReadLine-Perl

TOOL_DEPENDS+=		p5-Test-Class>=0.36:../../devel/p5-Test-Class
TOOL_DEPENDS+=		p5-Test-Deep>=0.108:../../devel/p5-Test-Deep
#TOOL_DEPENDS+=	{perl>=5.14.2,p5-Test-Simple>=0.98}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Debug/Client/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
