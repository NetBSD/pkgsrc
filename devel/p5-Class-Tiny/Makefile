# $NetBSD: Makefile,v 1.13 2020/08/31 18:07:40 wiz Exp $

DISTNAME=	Class-Tiny-1.006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Tiny
COMMENT=	Perl extension for minimalist class construction
LICENSE=	apache-2.0

PERL5_PACKLIST=		auto/Class/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
