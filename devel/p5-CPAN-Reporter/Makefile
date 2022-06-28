# $NetBSD: Makefile,v 1.34 2022/06/28 11:31:57 wiz Exp $

DISTNAME=	CPAN-Reporter-1.2018
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CPAN-Reporter
COMMENT=	Adds CPAN Testers reporting to p5-CPAN
LICENSE=	apache-2.0

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/CPAN/Reporter/.packlist

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-CPAN-Reporter
PKG_SUPPORTED_OPTIONS+=	proc-processtable
PKG_SUGGESTED_OPTIONS+=	#empty

.include "../../mk/bsd.options.mk"

#DEPENDS+=	{perl>=5.10.1,p5-CPAN>=1.9301}:../../devel/p5-CPAN
DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Config-Tiny>=2.12:../../devel/p5-Config-Tiny
DEPENDS+=	p5-Devel-Autoflush>=0.04:../../devel/p5-Devel-Autoflush
#DEPENDS+=	{perl>=5.8.9,p5-ExtUtils-MakeMaker>=6.36}:../../devel/p5-ExtUtils-MakeMaker
DEPENDS+=	p5-File-Copy-Recursive>=0.35:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-File-HomeDir>=0.58:../../devel/p5-File-HomeDir
DEPENDS+=	p5-File-pushd>=0.32:../../devel/p5-File-pushd
DEPENDS+=	p5-IO-CaptureOutput>=1.03:../../devel/p5-IO-CaptureOutput
#DEPENDS+=	{perl>=5.10.1,p5-Parse-CPAN-Meta-[0-9]*}:../../devel/p5-Parse-CPAN-Meta
DEPENDS+=	p5-Probe-Perl-[0-9]*:../../devel/p5-Probe-Perl
#DEPENDS+=	{perl>=5.15.8,p5-IPC-Cmd>=0.76}:../../devel/p5-IPC-Cmd
DEPENDS+=	p5-Test-Reporter>=1.54:../../devel/p5-Test-Reporter

.if !empty(PKG_OPTIONS:Mproc-processtable)
DEPENDS+=	p5-Proc-ProcessTable>=0.45:../../devel/p5-Proc-ProcessTable
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
