# $NetBSD: Makefile,v 1.2 2024/11/16 12:04:49 wiz Exp $

DISTNAME=	Overload-FileCheck-0.013
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AT/ATOOMIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Overload::FileCheck
COMMENT=	Override/mock perl file check -X
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Overload/FileCheck/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
