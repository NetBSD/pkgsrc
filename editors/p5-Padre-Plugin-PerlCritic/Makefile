# $NetBSD: Makefile,v 1.22 2023/07/06 09:40:32 wiz Exp $
#

DISTNAME=	Padre-Plugin-PerlCritic-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	editors devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Padre-Plugin-PerlCritic
COMMENT=	Analyze perl files in Padre with Perl::Critic
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Locale-Msgfmt>=0.15:../../devel/p5-Locale-Msgfmt

DEPENDS+=	p5-Padre>=0.57:../../editors/p5-Padre
DEPENDS+=	p5-Perl-Critic-[0-9]*:../../devel/p5-Perl-Critic

PERL5_PACKLIST=		auto/Padre/Plugin/PerlCritic/.packlist
PERL5_MODULE_TYPE=	Module::Build

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
