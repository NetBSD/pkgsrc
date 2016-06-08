# $NetBSD: Makefile,v 1.21 2016/06/08 19:23:20 wiz Exp $

DISTNAME=	Object-Realize-Later-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Object-Realize-Later/
COMMENT=	Delayed creation of objects
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
BUILD_DEPENDS+=	p5-Test-Pod>=1.00:../../devel/p5-Test-Pod

PERL5_PACKLIST=	auto/Object/Realize/Later/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
