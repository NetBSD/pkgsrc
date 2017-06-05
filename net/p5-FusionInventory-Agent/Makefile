# $NetBSD: Makefile,v 1.9 2017/06/05 14:24:17 ryoon Exp $
#

DISTNAME=	FusionInventory-Agent-2.2.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FU/FUSINV/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~fusinv/
COMMENT=	Fusion Inventory agent
LICENSE=	gnu-gpl-v2

PKG_SYSCONFSUBDIR?=	fusioninventory
EGDIR=		${PREFIX}/share/examples/fusioninventory
CONF_FILES+=	${EGDIR}/agent.cfg ${PKG_SYSCONFDIR}/agent.cfg

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
DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
DEPENDS+=	p5-Test-MockModule-[0-9]*:../../devel/p5-Test-MockModule
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML

PERL5_PACKLIST= auto/FusionInventory/Agent/.packlist

PERL5_MODULE_TYPE=	Module::Install::Bundled

MAKE_PARAMS+=	PREFIX=${PREFIX} LOCALSTATEDIR=${VARBASE}/fusioninventory
MAKE_PARAMS+=	SYSCONFDIR=${PKG_SYSCONFDIR} PKGMANDIR=${PKGMANDIR}

REPLACE_PERL+=	memconf

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
