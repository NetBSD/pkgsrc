# $NetBSD: Makefile,v 1.28 2023/07/06 09:41:17 wiz Exp $
#

DISTNAME=	LaTeX-Table-v1.0.6
PKGNAME=	p5-${DISTNAME:S/v1/1/}
PKGREVISION=	13
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LaTeX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/LaTeX-Table
COMMENT=	Perl extension for the automatic generation of LaTeX tables
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0.76:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-FollowPBP>=0.03:../../devel/p5-MooseX-FollowPBP
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit

# for make test
TOOL_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
TOOL_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager
TOOL_DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable

# Recommended modules
DEPENDS+=	p5-LaTeX-Driver-[0-9]*:../../print/p5-LaTeX-Driver
DEPENDS+=	p5-LaTeX-Encode-[0-9]*:../../print/p5-LaTeX-Encode
DEPENDS+=	p5-Number-Format-[0-9]*:../../textproc/p5-Number-Format
DEPENDS+=	p5-Text-CSV-[0-9]*:../../textproc/p5-Text-CSV
#DEPENDS+=	{perl>=5.10.1,p5-autodie-[0-9]*}:../../devel/p5-autodie

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/LaTeX/Table/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
