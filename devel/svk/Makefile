# $NetBSD: Makefile,v 1.47 2019/08/11 13:20:52 wiz Exp $

DISTNAME=	SVK-v2.2.3
PKGNAME=	svk-2.2.3
PKGREVISION=	9
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://svk.bestpractical.com/
COMMENT=	Decentralized version control system built on Subversion
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-subversion>=1.4.0:../../devel/p5-subversion
DEPENDS+=	p5-Algorithm-Annotate>=0.10:../../devel/p5-Algorithm-Annotate
DEPENDS+=	p5-Algorithm-Diff>=1.19.01:../../devel/p5-Algorithm-Diff
DEPENDS+=	p5-App-CLI>=0.07:../../devel/p5-App-CLI
DEPENDS+=	p5-Class-Accessor>=0.25:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Autouse>=1.15:../../devel/p5-Class-Autouse
DEPENDS+=	p5-Class-Data-Inheritable>=0.06:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Data-Hierarchy>=0.30:../../devel/p5-Data-Hierarchy
#DEPENDS+=	{perl>=5.10.0,p5-File-Temp>=0.17}:../../devel/p5-File-Temp
DEPENDS+=	p5-File-Type>=0.22:../../devel/p5-File-Type
DEPENDS+=	p5-IO-Digest>=0.10:../../devel/p5-IO-Digest
DEPENDS+=	p5-List-MoreUtils>=0.22:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Path-Class>=0.16:../../devel/p5-Path-Class
#DEPENDS+=	{perl>=5.10.0,p5-PathTools>=3.19}:../../devel/p5-PathTools
DEPENDS+=	p5-PerlIO-eol>=0.13:../../devel/p5-PerlIO-eol
DEPENDS+=	p5-PerlIO-via-dynamic>=0.11:../../devel/p5-PerlIO-via-dynamic
DEPENDS+=	p5-PerlIO-via-symlink>=0.02:../../devel/p5-PerlIO-via-symlink
#DEPENDS+=	{perl>=5.10.0,p5-Pod-Escapes>=1.04}:../../textproc/p5-Pod-Escapes
#DEPENDS+=	{perl>=5.10.0,p5-Pod-Simple>=3.02}:../../textproc/p5-Pod-Simple
DEPENDS+=	p5-SVN-Simple>=0.27:../../devel/p5-SVN-Simple
DEPENDS+=	p5-Term-ReadKey>=2.30:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Time-Progress>=1.3:../../time/p5-Time-Progress
DEPENDS+=	p5-URI>=1.30:../../www/p5-URI
DEPENDS+=	p5-UNIVERSAL-require>=0.10:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-YAML-Syck>=0.60:../../textproc/p5-YAML-Syck
#DEPENDS+=	{perl>=5.10.0,p5-version>=0.68}:../../devel/p5-version

# bootstrap feature dependencies
DEPENDS+=	p5-PerlIO-via-Bzip2-[0-9]*:../../devel/p5-PerlIO-via-Bzip2
DEPENDS+=	p5-PerlIO-gzip-[0-9]*:../../devel/p5-PerlIO-gzip
DEPENDS+=	p5-SVN-Dump>=0.04:../../devel/p5-SVN-Dump
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

# localized messages
DEPENDS+=	p5-Locale-Maketext-Lexicon>=0.62:../../misc/p5-Locale-Maketext-Lexicon
#DEPENDS+=	{perl>=5.10.0,p5-Locale-Maketext-Simple>=0.16}:../../misc/p5-Locale-Maketext-Simple

# message display though a pager
DEPENDS+=	p5-IO-Pager>=0.06:../../devel/p5-IO-Pager

# Log::log4perl support
DEPENDS+=	p5-Log-Log4perl-[0-9]*:../../devel/p5-Log-Log4perl

# SVN::Mirror support
DEPENDS+=	p5-SVN-Mirror>=0.71:../../devel/p5-SVN-Mirror

# Patch management
#DEPENDS+=	{perl>=5.9.3,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress	# Compress::Zlib>=0
DEPENDS+=	p5-FreezeThaw>=0.43:../../devel/p5-FreezeThaw

PERL5_PACKLIST=		auto/SVK/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
