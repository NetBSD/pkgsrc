# $NetBSD: Makefile,v 1.9 2022/06/28 11:32:05 wiz Exp $

DISTNAME=	Clone-Choose-0.010
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HE/HERMES/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Clone-Choose
COMMENT=	Perl5 module to choose appropriate clone utility
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
BUILD_DEPENDS+=	p5-Clone-PP-[0-9]*:../../devel/p5-Clone-PP

PERL5_PACKLIST=		auto/Clone/Choose/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
