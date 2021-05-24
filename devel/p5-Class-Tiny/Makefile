# $NetBSD: Makefile,v 1.15 2021/05/24 19:50:19 wiz Exp $

DISTNAME=	Class-Tiny-1.008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Tiny
COMMENT=	Perl extension for minimalist class construction
LICENSE=	apache-2.0

PERL5_PACKLIST=		auto/Class/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
