# $NetBSD: Makefile,v 1.16 2021/05/24 19:50:19 wiz Exp $

DISTNAME=	Class-Throwable-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Throwable
COMMENT=	Minimal lightweight exception class
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Throwable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
