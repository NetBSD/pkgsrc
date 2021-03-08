# $NetBSD: Makefile,v 1.17 2021/03/08 06:23:46 wen Exp $
#

DISTNAME=		Test-File-1.448
PKGNAME=		p5-Test-File-1.44.8
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-File
COMMENT=		Test file attributes
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/File/.packlist

BUILD_DEPENDS+=		p5-Test-utf8>=0:../../devel/p5-Test-utf8

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
