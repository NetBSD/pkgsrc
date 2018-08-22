# $NetBSD: Makefile,v 1.6 2018/08/22 09:45:36 wiz Exp $

DISTNAME=	Algorithm-Munkres-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-Munkres
COMMENT=	Munkres Assignment for square and rectangular matrices
LICENSE=	gnu-gpl-v2

PERL5_PACKLIST=	auto/Algorithm/Munkres/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
