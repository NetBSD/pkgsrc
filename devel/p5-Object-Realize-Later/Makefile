# $NetBSD: Makefile,v 1.25 2019/06/30 20:15:30 nia Exp $

DISTNAME=	Object-Realize-Later-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Object-Realize-Later
COMMENT=	Delayed creation of objects
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
BUILD_DEPENDS+=	p5-Test-Pod>=1.00:../../devel/p5-Test-Pod

PERL5_PACKLIST=	auto/Object/Realize/Later/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
