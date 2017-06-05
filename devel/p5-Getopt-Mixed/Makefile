# $NetBSD: Makefile,v 1.15 2017/06/05 14:23:03 ryoon Exp $

DISTNAME=	Getopt-Mixed-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rsavage/Getopt-Mixed/
COMMENT=	Mixed Getopt wrapper
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Getopt/Mixed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
