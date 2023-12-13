# $NetBSD: Makefile,v 1.30 2023/12/13 13:24:11 mef Exp $

DISTNAME=	CPAN-Meta-Check-0.018
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CPAN-Meta-Check
COMMENT=	Perl module to verify requirements in a CPAN::Meta object
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CPAN/Meta/Check/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
