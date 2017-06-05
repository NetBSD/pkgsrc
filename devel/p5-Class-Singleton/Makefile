# $NetBSD: Makefile,v 1.19 2017/06/05 14:22:43 ryoon Exp $

DISTNAME=	Class-Singleton-1.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Singleton/
COMMENT=	Perl module to implement Singleton classes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Singleton/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
