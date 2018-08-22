# $NetBSD: Makefile,v 1.27 2018/08/22 09:43:55 wiz Exp $

DISTNAME=	Devel-REPL-1.003028
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-REPL/
COMMENT=	Modern Perl interactive shell
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-Moose>=0.74:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-AttributeHelpers>=0.16:../../devel/p5-MooseX-AttributeHelpers
DEPENDS+=	p5-MooseX-Getopt>=0.18:../../devel/p5-MooseX-Getopt
DEPENDS+=	p5-MooseX-Object-Pluggable>=0.0009:../../devel/p5-MooseX-Object-Pluggable
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

# Recommended dependencies
DEPENDS+=	p5-App-Nopaste-[0-9]*:../../www/p5-App-Nopaste
DEPENDS+=	p5-B-Keywords-[0-9]*:../../devel/p5-B-Keywords
DEPENDS+=	p5-Data-Dumper-Concise-[0-9]*:../../devel/p5-Data-Dumper-Concise
DEPENDS+=	p5-Data-Dump-Streamer-[0-9]*:../../devel/p5-Data-Dump-Streamer
DEPENDS+=	p5-File-Next-[0-9]*:../../devel/p5-File-Next
DEPENDS+=	p5-Lexical-Persistence-[0-9]*:../../devel/p5-Lexical-Persistence
DEPENDS+=	p5-Module-Refresh-[0-9]*:../../devel/p5-Module-Refresh
DEPENDS+=	p5-PPI-[0-9]*:../../devel/p5-PPI
DEPENDS+=	p5-Sys-SigAction-[0-9]*:../../sysutils/p5-Sys-SigAction

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Install::Bundled
PERL5_PACKLIST=		auto/Devel/REPL/.packlist
REPLACE_PERL+=		script/re.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
