# $NetBSD: Makefile,v 1.6 2023/12/16 11:37:02 mef Exp $

DISTNAME=	File-Valet-1.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Valet
COMMENT=	Perl5 file utilities
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS=	p5-Test-Most>=0:../../devel/p5-Test-Most

PERL5_PACKLIST=		auto/File/Valet/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
