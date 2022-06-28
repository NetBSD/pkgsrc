# $NetBSD: Makefile,v 1.18 2022/06/28 11:35:13 wiz Exp $
#

DISTNAME=	Net-SNMP-Mixin-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-SNMP-Mixin
COMMENT=	Perl 5 module providing a mixin framework for Net::SNMP
LICENSE=	${PERL5_LICENSE}

MAKE_ENV+=		PERL_MM_USE_DEFAULT=1
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-Net-SNMP-[0-9]*:../../net/p5-Net-SNMP
DEPENDS+=	p5-Package-Generator>=0.102:../../devel/p5-Package-Generator
DEPENDS+=	p5-Sub-Exporter>=0.978:../../devel/p5-Sub-Exporter

PERL5_PACKLIST=		auto/Net/SNMP/Mixin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
