# $NetBSD: Makefile,v 1.13 2019/08/11 13:22:21 wiz Exp $

DISTNAME=	Net-Libdnet6-0.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	perl5 net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Libdnet6
COMMENT=	Adds IPv6 support to Net::Libdnet
LICENSE=	artistic

DEPENDS+=	p5-Net-Libdnet-[0-9]*:../../net/p5-Net-Libdnet
DEPENDS+=	p5-Net-IPv6Addr-[0-9]*:../../net/p5-Net-IPv6Addr

PERL5_PACKLIST=	auto/Net/Libdnet6/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
