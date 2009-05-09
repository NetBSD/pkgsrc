# $NetBSD: Makefile,v 1.8 2009/05/09 17:26:10 seb Exp $
#

DISTNAME=	Devel-REPL-1.003006
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-REPL/
COMMENT=	Modern Perl interactive shell

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Devel/REPL/.packlist

DEPENDS+=	p5-App-Nopaste-[0-9]*:../../www/p5-App-Nopaste
DEPENDS+=	p5-B-Keywords-[0-9]*:../../devel/p5-B-Keywords
DEPENDS+=	p5-Data-Dump-Streamer-[0-9]*:../../devel/p5-Data-Dump-Streamer
DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-File-Next-[0-9]*:../../devel/p5-File-Next
DEPENDS+=	p5-Lexical-Persistence-[0-9]*:../../devel/p5-Lexical-Persistence
DEPENDS+=	p5-Module-Refresh-[0-9]*:../../devel/p5-Module-Refresh
DEPENDS+=	p5-Moose>=0.64:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-AttributeHelpers>=0.14:../../devel/p5-MooseX-AttributeHelpers
DEPENDS+=	p5-MooseX-Getopt>=0.15:../../devel/p5-MooseX-Getopt
DEPENDS+=	p5-MooseX-Object-Pluggable>=0.0009:../../devel/p5-MooseX-Object-Pluggable
DEPENDS+=	p5-PPI-[0-9]*:../../devel/p5-PPI
DEPENDS+=	p5-PathTools-[0-9]*:../../devel/p5-PathTools
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Term-ANSIColor-[0-9]*:../../devel/p5-Term-ANSIColor
DEPENDS+=	p5-Term-ReadLine-[0-9]*:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
