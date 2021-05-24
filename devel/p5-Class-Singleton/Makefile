# $NetBSD: Makefile,v 1.25 2021/05/24 19:50:18 wiz Exp $

DISTNAME=	Class-Singleton-1.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Singleton
COMMENT=	Perl module to implement Singleton classes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Singleton/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
