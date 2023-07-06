# $NetBSD: Makefile,v 1.27 2023/07/06 09:40:15 wiz Exp $

DISTNAME=		Test-Manifest-2.023
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Manifest
COMMENT=		Perl5 module to choose test order
LICENSE=		artistic-2.0

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Manifest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
