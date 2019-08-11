# $NetBSD: Makefile,v 1.15 2019/08/11 13:20:30 wiz Exp $
#

DISTNAME=		Test-File-1.443
PKGNAME=		p5-Test-File-1.44.3
PKGREVISION=		3
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
