# $NetBSD: Makefile,v 1.13 2022/06/28 11:33:09 wiz Exp $

DISTNAME=		Reply-0.42
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		11
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DO/DOY/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Reply
COMMENT=		Perl read, eval, print, loop, yay!
LICENSE=		mit

# recommended:
# p5-App-Nopaste-[0-9]*
# p5-B-Keywords-[0-9]*
# p5-Carp-Always-[0-9]*
# p5-Class-Refresh>=0.05
# p5-Data-Dump-[0-9]*
# p5-Data-Printer-[0-9]*
# p5-IO-Pager-[0-9]*
# p5-Proc-InvokeEditor-[0-9]*
# p5-Term-ReadKey-[0-9]*

DEPENDS+=		p5-Config-INI-Reader-Ordered-[0-9]*:../../devel/p5-Config-INI-Reader-Ordered
DEPENDS+=		p5-Data-Dumper-[0-9]*:../../devel/p5-Data-Dumper
DEPENDS+=		p5-Devel-LexAlias-[0-9]*:../../devel/p5-Devel-LexAlias
DEPENDS+=		p5-Eval-Closure>=0.11:../../devel/p5-Eval-Closure
DEPENDS+=		p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=		p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
DEPENDS+=		p5-Package-Stash-[0-9]*:../../devel/p5-Package-Stash
DEPENDS+=		p5-PadWalker-[0-9]*:../../devel/p5-PadWalker
DEPENDS+=		p5-Term-ReadLine-Gnu-[0-9]*:../../devel/p5-Term-ReadLine-Gnu
DEPENDS+=		p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Reply/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
