# $NetBSD: Makefile,v 1.1.1.1 2008/10/07 13:40:03 seb Exp $
#

DISTNAME=	Devel-REPL-1.002001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-REPL/
COMMENT=	Modern Perl interactive shell

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Devel/REPL/.packlist

DEPENDS+=	p5-B-Keywords-[0-9]*:../../devel/p5-B-Keywords
DEPENDS+=	p5-Data-Dump-Streamer-[0-9]*:../../devel/p5-Data-Dump-Streamer
DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-Lexical-Persistence-[0-9]*:../../devel/p5-Lexical-Persistence
DEPENDS+=	p5-Moose>=0.38:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Getopt-[0-9]*:../../devel/p5-MooseX-Getopt
DEPENDS+=	p5-MooseX-Object-Pluggable>=0.0007:../../devel/p5-MooseX-Object-Pluggable
DEPENDS+=	p5-PPI-[0-9]*:../../devel/p5-PPI
DEPENDS+=	p5-PathTools-[0-9]*:../../devel/p5-PathTools
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Term-ReadLine-[0-9]*:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
