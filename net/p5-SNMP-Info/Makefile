# $NetBSD: Makefile,v 1.48 2022/06/28 11:35:17 wiz Exp $

DISTNAME=	SNMP-Info-3.78
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SNMP/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SNMP-Info
#HOMEPAGE=	http://snmp-info.sourceforge.net/
COMMENT=	Perl5 object oriented interface to SNMP informations
LICENSE=	modified-bsd

DEPENDS+=	net-snmp>=5.1.2:../../net/net-snmp
DEPENDS+=	p5-NetAddr-IP>=4.068:../../net/p5-NetAddr-IP

PERL5_PACKLIST=		auto/SNMP/Info/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
