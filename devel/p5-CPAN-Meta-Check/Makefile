# $NetBSD: Makefile,v 1.26 2021/05/24 19:50:11 wiz Exp $

DISTNAME=	CPAN-Meta-Check-0.014
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CPAN-Meta-Check
COMMENT=	Perl module to verify requirements in a CPAN::Meta object
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

PERL5_PACKLIST=		auto/CPAN/Meta/Check/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
