# $NetBSD: Makefile,v 1.11 2022/06/28 11:35:18 wiz Exp $

DISTNAME=	Zabbix-Sender-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Zabbix/}
CATEGORIES=	net perl5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Pure-perl implementation of zabbix-sender
LICENSE=	artistic OR gnu-gpl-v1

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=	p5-Net-[0-9]*:../../net/p5-Net
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Output-[0-9]*:../../devel/p5-Test-Output

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Zabbix/Sender/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
