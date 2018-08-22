# $NetBSD: Makefile,v 1.19 2018/08/22 09:44:47 wiz Exp $

DISTNAME=		Test-Manifest-2.021
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Manifest/
COMMENT=		Perl5 module to choose test order
#LICENSE=		${PERL5_LICENSE}
LICENSE=		artistic-2.0

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Manifest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
