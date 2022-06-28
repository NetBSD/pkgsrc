# $NetBSD: Makefile,v 1.19 2022/06/28 11:33:47 wiz Exp $

DISTNAME=	Padre-Plugin-DataWalker-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Padre-Plugin-DataWalker
COMMENT=	Simple Perl data structure browser Padre
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Padre>=0.47:../../editors/p5-Padre
DEPENDS+=	p5-Wx-Perl-DataWalker>=0.02:../../devel/p5-Wx-Perl-DataWalker
DEPENDS+=	p5-YAML-LibYAML-[0-9]*:../../textproc/p5-YAML-LibYAML

BUILD_DEPENDS+=	p5-Locale-Msgfmt>=0.14:../../devel/p5-Locale-Msgfmt

PERL5_PACKLIST=		auto/Padre/Plugin/DataWalker/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
