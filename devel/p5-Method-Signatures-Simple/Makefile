# $NetBSD: Makefile,v 1.23 2023/07/06 09:39:30 wiz Exp $

DISTNAME=	Method-Signatures-Simple-1.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RH/RHESA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Method::Signatures::Simple
COMMENT=	Basic signatures method declarations, without source filters
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-Declare>=0.003001:../../devel/p5-Devel-Declare

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Method/Signatures/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
