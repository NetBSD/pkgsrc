# $NetBSD: Makefile,v 1.26 2024/11/16 12:06:19 wiz Exp $

DISTNAME=	POE-Component-SNMP-1.1006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/POE-Component-SNMP
COMMENT=	Event-driven SNMP interface
LICENSE=	gnu-gpl-v2 OR artistic

DEPENDS+=	p5-Net-SNMP>=5.0.1:../../net/p5-Net-SNMP

PERL5_PACKLIST=		auto/POE/Component/SNMP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
