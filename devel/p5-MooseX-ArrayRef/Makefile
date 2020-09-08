# $NetBSD: Makefile,v 1.4 2020/09/08 13:09:54 wiz Exp $

DISTNAME=	MooseX-ArrayRef-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/T/TO/TOBYINK/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/MooseX::ArrayRef
COMMENT=	Blessed arrayrefs with Moose
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/MooseX/ArrayRef/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
