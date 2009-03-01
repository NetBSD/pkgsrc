# $NetBSD: Makefile,v 1.1 2009/03/01 23:58:09 sno Exp $

DISTNAME=	CPAN-Reporter-1.1705
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/${DISTNAME}/
COMMENT=	Adds CPAN Testers reporting to p5-CPAN

MAKE_PARAMS+=	verbose

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/CPAN/Reporter/.packlist

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-CPAN-Reporter
PKG_SUPPORTED_OPTIONS+=	proc-processtable
PKG_SUGGESTED_OPTIONS+=	#empty

.include "../../mk/bsd.options.mk"

DEPENDS+=	p5-Config-Tiny>=2.12:../../devel/p5-Config-Tiny
DEPENDS+=	p5-CPAN>=1.9301:../../devel/p5-CPAN
DEPENDS+=	p5-Parse-CPAN-Meta>=0.01:../../devel/p5-Parse-CPAN-Meta
DEPENDS+=	p5-File-Copy-Recursive>=0.35:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-Devel-Autoflush>=0.04:../../devel/p5-Devel-Autoflush
DEPENDS+=	p5-File-HomeDir>=0.58:../../devel/p5-File-HomeDir
DEPENDS+=	p5-File-pushd>=0.32:../../devel/p5-File-pushd
DEPENDS+=	p5-PathTools>=3.19:../../devel/p5-PathTools
DEPENDS+=	p5-Probe-Perl>=0.01:../../devel/p5-Probe-Perl
DEPENDS+=	p5-Tee>=0.13:../../devel/p5-Tee
DEPENDS+=	p5-Test-Reporter>=1.50:../../devel/p5-Test-Reporter

.if !empty(PKG_OPTIONS:Mproc-processtable)
DEPENDS+=	p5-Proc-ProcessTable>=0.45:../../devel/p5-Proc-ProcessTable
.endif

BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.36:../../devel/p5-ExtUtils-MakeMaker
BUILD_DEPENDS+=	p5-IO-CaptureOutput>=1.03:../../devel/p5-IO-CaptureOutput
BUILD_DEPENDS+=	p5-Test-Simple>=0.62:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
