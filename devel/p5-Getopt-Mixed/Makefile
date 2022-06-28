# $NetBSD: Makefile,v 1.22 2022/06/28 11:32:30 wiz Exp $

DISTNAME=	Getopt-Mixed-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Getopt-Mixed
COMMENT=	Mixed Getopt wrapper
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Getopt/Mixed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
