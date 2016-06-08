# $NetBSD: Makefile,v 1.14 2016/06/08 19:22:39 wiz Exp $

DISTNAME=	Class-Accessor-Chained-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor-Chained/
COMMENT=	Make chained accessors
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor

PERL5_PACKLIST=		auto/Class/Accessor/Chained/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
