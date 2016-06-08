# $NetBSD: Makefile,v 1.5 2016/06/08 19:22:54 wiz Exp $

DISTNAME=	ExtUtils-MakeMaker-Coverage-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://cpan.metacpan.org/authors/id/S/SM/SMPETERS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/S/SM/SMPETERS/
COMMENT=	Add a Makefile target to determine test coverage using Devel::Cover
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/ExtUtils/MakeMaker/Coverage/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
