# $NetBSD: Makefile,v 1.7 2022/06/28 11:32:51 wiz Exp $

DISTNAME=	MooseX-ArrayRef-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TOBYINK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/MooseX::ArrayRef
COMMENT=	Blessed arrayrefs with Moose
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/MooseX/ArrayRef/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
