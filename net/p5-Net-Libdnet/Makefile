# $NetBSD: Makefile,v 1.20 2019/08/11 13:22:21 wiz Exp $
#

DISTNAME=	Net-Libdnet-0.99
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}
#MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/V/VM/VMAN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Libdnet
COMMENT=	Perl interface to libdnet
LICENSE=	2-clause-bsd

PERL5_PACKLIST=	auto/Net/Libdnet/.packlist
USE_LANGUAGES+=	c

DEPENDS+= p5-Class-Gomor-[0-9]*:../../devel/p5-Class-Gomor

.include "../../net/libdnet/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
