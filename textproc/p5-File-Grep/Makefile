# $NetBSD: Makefile,v 1.3 2026/07/16 19:05:00 wiz Exp $
#

DISTNAME=		File-Grep-0.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/File-Grep
COMMENT=		Perl 5 module to grep a file
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Grep/.packlist
USE_LANGUAGES=		# none

REPLACE_PERL=		Grep.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
