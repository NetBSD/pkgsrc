# $NetBSD: Makefile,v 1.12 2021/05/24 19:53:01 wiz Exp $

DISTNAME=	Number-Tolerant-1.708
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Number-Tolerant
COMMENT=	Perl5 module for tolerance ranges for inexact numbers
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter>=0.950:../../devel/p5-Sub-Exporter

PERL5_PACKLIST=	auto/Number/Tolerant/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
