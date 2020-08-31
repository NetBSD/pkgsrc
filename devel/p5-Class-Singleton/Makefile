# $NetBSD: Makefile,v 1.23 2020/08/31 18:07:39 wiz Exp $

DISTNAME=	Class-Singleton-1.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Singleton
COMMENT=	Perl module to implement Singleton classes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Singleton/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
