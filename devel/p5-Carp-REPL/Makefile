# $NetBSD: Makefile,v 1.17 2019/06/30 20:14:37 nia Exp $

DISTNAME=	Carp-REPL-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Carp-REPL
COMMENT=	Perl 5 read-eval-print-loop on die and/or warn
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
USE_TOOLS+=	perl
PERL5_PACKLIST=	auto/Carp/REPL/.packlist

DEPENDS+=	p5-Data-Dump-Streamer-[0-9]*:../../devel/p5-Data-Dump-Streamer
DEPENDS+=	p5-Devel-LexAlias-[0-9]*:../../devel/p5-Devel-LexAlias
DEPENDS+=	p5-Devel-REPL-[0-9]*:../../devel/p5-Devel-REPL
DEPENDS+=	p5-Devel-StackTrace-WithLexicals-[0-9]*:../../devel/p5-Devel-StackTrace-WithLexicals
DEPENDS+=	p5-Lexical-Persistence-[0-9]*:../../devel/p5-Lexical-Persistence
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

# For test target
BUILD_DEPENDS+=	p5-Test-Expect-[0-9]*:../../devel/p5-Test-Expect

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
