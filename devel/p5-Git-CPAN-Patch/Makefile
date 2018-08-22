# $NetBSD: Makefile,v 1.23 2018/08/22 09:44:05 wiz Exp $

DISTNAME=	Git-CPAN-Patch-2.3.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Git/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Git-CPAN-Patch/
COMMENT=	Patch CPAN modules using Git
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL=	bin/git-cpan

DEPENDS+=	p5-Archive-Any-[0-9]*:../../archivers/p5-Archive-Any
DEPENDS+=	p5-BackPAN-Index>=0.39:../../devel/p5-BackPAN-Index
DEPENDS+=	p5-CPANPLUS-[0-9]*:../../devel/p5-CPANPLUS
DEPENDS+=	p5-CPAN-ParseDistribution-[0-9]*:../../devel/p5-CPAN-ParseDistribution
DEPENDS+=	p5-CLASS-[0-9]*:../../devel/p5-CLASS
DEPENDS+=	p5-DateTime-Format-W3CDTF-[0-9]*:../../time/p5-DateTime-Format-W3CDTF
DEPENDS+=	p5-File-chdir-[0-9]*:../../devel/p5-File-chdir
DEPENDS+=	p5-File-chmod-[0-9]*:../../sysutils/p5-File-chmod
DEPENDS+=	p5-Git-Repository-[0-9]*:../../devel/p5-Git-Repository
DEPENDS+=	p5-Git-Repository-Plugin-AUTOLOAD-[0-9]*:../../devel/p5-Git-Repository-Plugin-AUTOLOAD
DEPENDS+=	p5-List-Pairwise-[0-9]*:../../devel/p5-List-Pairwise
DEPENDS+=	p5-MetaCPAN-API-[0-9]*:../../devel/p5-MetaCPAN-API
DEPENDS+=	p5-Method-Signatures-Simple-[0-9]*:../../devel/p5-Method-Signatures-Simple
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-App-[0-9]*:../../devel/p5-MooseX-App
DEPENDS+=	p5-MooseX-App-Cmd-[0-9]*:../../devel/p5-MooseX-App-Cmd
DEPENDS+=	p5-MooseX-SemiAffordanceAccessor-[0-9]*:../../devel/p5-MooseX-SemiAffordanceAccessor
DEPENDS+=	p5-MooseX-Role-Tempdir-[0-9]*:../../devel/p5-MooseX-Role-Tempdir
DEPENDS+=	p5-Test-MockObject-[0-9]*:../../devel/p5-Test-MockObject
#DEPENDS+=	{perl>=5.10.1,p5-autodie-[0-9]*}:../../devel/p5-autodie
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww # LWP::UserAgent

# for make test
BUILD_DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny
BUILD_DEPENDS+=	p5-Pod-Elemental-[0-9]*:../../textproc/p5-Pod-Elemental
BUILD_DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
BUILD_DEPENDS+=	p5-MetaCPAN-Client-[0-9]*:../../devel/p5-MetaCPAN-Client
BUILD_DEPENDS+=	p5-Data-Printer-[0-9]*:../../devel/p5-Data-Printer
BUILD_DEPENDS+=	p5-Devel-CheckOS-[0-9]*:../../devel/p5-Devel-CheckOS
BUILD_DEPENDS+=	p5-Package-Constants-[0-9]*:../../devel/p5-Package-Constants
BUILD_DEPENDS+=	p5-Parallel-ForkManager-[0-9]*:../../devel/p5-Parallel-ForkManager
BUILD_DEPENDS+=	p5-Search-Elasticsearch-[0-9]*:../../devel/p5-Search-Elasticsearch
BUILD_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Git/CPAN/Patch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
