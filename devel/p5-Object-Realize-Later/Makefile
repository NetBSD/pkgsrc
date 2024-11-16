# $NetBSD: Makefile,v 1.32 2024/11/16 12:04:49 wiz Exp $

DISTNAME=	Object-Realize-Later-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Object-Realize-Later
COMMENT=	Delayed creation of objects
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
TOOL_DEPENDS+=	p5-Test-Pod>=1.00:../../devel/p5-Test-Pod

PERL5_PACKLIST=	auto/Object/Realize/Later/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
