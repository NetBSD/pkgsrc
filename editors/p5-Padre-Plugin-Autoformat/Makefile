# $NetBSD: Makefile,v 1.17 2022/06/28 11:33:47 wiz Exp $

DISTNAME=	Padre-Plugin-Autoformat-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Padre-Plugin-Autoformat
COMMENT=	Reformat text within Padre
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Util-[0-9]*:../../devel/p5-Module-Util
DEPENDS+=	p5-Padre>=0.30:../../editors/p5-Padre
DEPENDS+=	p5-Text-Autoformat-[0-9]*:../../textproc/p5-Text-Autoformat

PERL5_PACKLIST=		auto/Padre/Plugin/Autoformat/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
