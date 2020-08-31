# $NetBSD: Makefile,v 1.9 2020/08/31 18:08:50 wiz Exp $

DISTNAME=	Signal-Mask-0.008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://cpan.metacpan.org/authors/id/L/LE/LEONT/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/L/LE/LEONT/
HOMEPAGE=	https://metacpan.org/pod/Signal::Mask
COMMENT=	Signal::Mask - Signal masks made easy
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-IPC-Signal-[0-9]*:../../devel/p5-IPC-Signal

PERL5_PACKLIST=	auto/Signal/Mask/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
