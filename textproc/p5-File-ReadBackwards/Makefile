# $NetBSD: Makefile,v 1.18 2021/04/23 06:56:49 schmonz Exp $
#

DISTNAME=		File-ReadBackwards-1.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/File-ReadBackwards
COMMENT=		Perl 5 module to read a file backwards by lines
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/ReadBackwards/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
