# $NetBSD: Makefile,v 1.14 2018/08/22 09:46:49 wiz Exp $
#

DISTNAME=		File-ReadBackwards-1.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-ReadBackwards/
COMMENT=		Perl 5 module to read a file backwards by lines
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/ReadBackwards/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
