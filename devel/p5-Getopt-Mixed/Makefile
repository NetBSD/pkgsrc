# $NetBSD: Makefile,v 1.17 2018/08/22 09:44:04 wiz Exp $

DISTNAME=	Getopt-Mixed-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~cjm/Getopt-Mixed/
COMMENT=	Mixed Getopt wrapper
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Getopt/Mixed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
