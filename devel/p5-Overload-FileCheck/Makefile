# $NetBSD: Makefile,v 1.1 2024/02/10 01:14:51 schmonz Exp $

DISTNAME=	Overload-FileCheck-0.013
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AT/ATOOMIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Overload::FileCheck
COMMENT=	Override/mock perl file check -X
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Overload/FileCheck/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
