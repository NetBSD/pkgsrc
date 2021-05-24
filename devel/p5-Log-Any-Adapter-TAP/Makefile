# $NetBSD: Makefile,v 1.7 2021/05/24 19:50:57 wiz Exp $

DISTNAME=	Log-Any-Adapter-TAP-0.003003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NE/NERDVANA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Log-Any-Adapter-TAP
COMMENT=	Logging adapter suitable for use in TAP testcases
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Log-Any-[0-9]*:../../devel/p5-Log-Any
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

PERL5_PACKLIST=	auto/Log/Any/Adapter/TAP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
