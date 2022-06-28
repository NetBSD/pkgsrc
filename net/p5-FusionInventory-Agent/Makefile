# $NetBSD: Makefile,v 1.23 2022/06/28 11:35:06 wiz Exp $

DISTNAME=	FusionInventory-Agent-2.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GB/GBOUGARD/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/FusionInventory-Agent
COMMENT=	Fusion Inventory agent
LICENSE=	gnu-gpl-v2

PKG_SYSCONFSUBDIR?=	fusioninventory
EGDIR=			${PREFIX}/share/examples/fusioninventory
CONF_FILES+=		${EGDIR}/agent.cfg ${PKG_SYSCONFDIR}/agent.cfg
CONF_FILES+=		${EGDIR}/inventory-server-plugin.cfg ${PKG_SYSCONFDIR}/inventory-server-plugin.cfg
CONF_FILES+=		${EGDIR}/server-test-plugin.cfg ${PKG_SYSCONFDIR}/server-test-plugin.cfg
CONF_FILES+=		${EGDIR}/ssl-server-plugin.cfg ${PKG_SYSCONFDIR}/ssl-server-plugin.cfg

BUILD_DEFS+=	VARBASE

OWN_DIRS+=	${VARBASE}/fusioninventory

DEPENDS+=	p5-HTTP-Server-Simple-Authen-[0-9]*:../../www/p5-HTTP-Server-Simple-Authen
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
DEPENDS+=	p5-Net-IP-[0-9]*:../../net/p5-Net-IP
DEPENDS+=	p5-Text-Template-[0-9]*:../../textproc/p5-Text-Template
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-XML-TreePP-[0-9]*:../../textproc/p5-XML-TreePP
DEPENDS+=	p5-HTTP-Proxy-[0-9]*:../../www/p5-HTTP-Proxy
DEPENDS+=	p5-HTTP-Server-Simple-[0-9]*:../../www/p5-HTTP-Server-Simple
DEPENDS+=	p5-IO-Capture-[0-9]*:../../devel/p5-IO-Capture
DEPENDS+=	p5-IPC-Run-[0-9]*:../../devel/p5-IPC-Run
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-YAML-Tiny-[0-9]*:../../textproc/p5-YAML-Tiny
DEPENDS+=	p5-SUPER-[0-9]*:../../devel/p5-SUPER
DEPENDS+=	p5-Net-SNMP-[0-9]*:../../net/p5-Net-SNMP
DEPENDS+=	p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive
# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-MockModule-[0-9]*:../../devel/p5-Test-MockModule
BUILD_DEPENDS+=	p5-Test-MockObject-[0-9]*:../../devel/p5-Test-MockObject
BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

PERL5_PACKLIST=	auto/FusionInventory/Agent/.packlist

PERL5_MODULE_TYPE=	Module::Install::Bundled

MAKE_PARAMS+=	PREFIX=${PREFIX} LOCALSTATEDIR=${VARBASE}/fusioninventory
MAKE_PARAMS+=	SYSCONFDIR=${PKG_SYSCONFDIR} PKGMANDIR=${PKGMANDIR}

USE_TOOLS+=	perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
