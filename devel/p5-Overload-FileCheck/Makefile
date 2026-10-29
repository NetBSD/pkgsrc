# $NetBSD: Makefile,v 1.5 2026/10/29 11:32:02 wen Exp $

DISTNAME=	Overload-FileCheck-0.015
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AT/ATOOMIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Overload::FileCheck
COMMENT=	Override/mock perl file check -X
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test2-Tools-Explain>=0:../../devel/p5-Test2-Tools-Explain

PERL5_PACKLIST=	auto/Overload/FileCheck/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
