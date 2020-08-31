# $NetBSD: Makefile,v 1.20 2020/08/31 18:08:06 wiz Exp $

DISTNAME=	Getopt-Mixed-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Getopt-Mixed
COMMENT=	Mixed Getopt wrapper
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Getopt/Mixed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
