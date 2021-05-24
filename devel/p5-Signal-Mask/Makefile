# $NetBSD: Makefile,v 1.12 2021/05/24 19:51:32 wiz Exp $

DISTNAME=	Signal-Mask-0.008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LE/LEONT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Signal::Mask
COMMENT=	Signal::Mask - Signal masks made easy
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-IPC-Signal-[0-9]*:../../devel/p5-IPC-Signal

PERL5_PACKLIST=	auto/Signal/Mask/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
