# $NetBSD: Makefile,v 1.6 2021/05/24 19:51:09 wiz Exp $

DISTNAME=	MooseX-ArrayRef-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TOBYINK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/MooseX::ArrayRef
COMMENT=	Blessed arrayrefs with Moose
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/MooseX/ArrayRef/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
