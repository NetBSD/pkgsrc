# $NetBSD: Makefile,v 1.1.1.1 2004/02/17 03:10:41 minskim Exp $

DISTNAME=	Object-Realize-Later-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://search.cpan.org/dist/Object-Realize-Later/
COMMENT=	Delayed creation of objects

DEPENDS+=	p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Object/Realize/Later/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
