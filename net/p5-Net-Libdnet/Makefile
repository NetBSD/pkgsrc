# $NetBSD: Makefile,v 1.27 2024/11/16 12:06:15 wiz Exp $
#

DISTNAME=	Net-Libdnet-0.99
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/V/VM/VMAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Libdnet
COMMENT=	Perl interface to libdnet
LICENSE=	2-clause-bsd

PERL5_PACKLIST=	auto/Net/Libdnet/.packlist
USE_LANGUAGES+=	c

DEPENDS+=	p5-Class-Gomor-[0-9]*:../../devel/p5-Class-Gomor

.include "../../net/libdnet/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
