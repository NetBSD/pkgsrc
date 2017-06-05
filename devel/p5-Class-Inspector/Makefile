# $NetBSD: Makefile,v 1.25 2017/06/05 14:22:42 ryoon Exp $

DISTNAME=	Class-Inspector-1.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Inspector/
COMMENT=	Provides information about Classes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Inspector/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
