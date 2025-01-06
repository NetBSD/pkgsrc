# $NetBSD: Makefile,v 1.4 2025/01/06 21:49:07 ktnb Exp $

DISTNAME=	pce-0.2.2
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.hampa.ch/pub/pce/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.hampa.ch/pce/
COMMENT=	PC Emulator
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

PKG_SYSCONFSUBDIR=	pce

CONF_FILES+=	share/pce/pce-ibmpc.cfg ${PKG_SYSCONFDIR}/pce-ibmpc.cfg
CONF_FILES+=	share/pce/pce-mac-classic.cfg ${PKG_SYSCONFDIR}/pce-mac-classic.cfg
CONF_FILES+=	share/pce/pce-mac-plus.cfg ${PKG_SYSCONFDIR}/pce-mac-plus.cfg
CONF_FILES+=	share/pce/pce-mac-se.cfg ${PKG_SYSCONFDIR}/pce-mac-se.cfg
CONF_FILES+=	share/pce/pce-rc759.cfg ${PKG_SYSCONFDIR}/pce-rc759.cfg
CONF_FILES+=	share/pce/pce-sim405.cfg ${PKG_SYSCONFDIR}/pce-sim405.cfg
CONF_FILES+=	share/pce/pce-sim6502.cfg ${PKG_SYSCONFDIR}/pce-sim6502.cfg
CONF_FILES+=	share/pce/pce-simarm.cfg ${PKG_SYSCONFDIR}/pce-simarm.cfg
CONF_FILES+=	share/pce/pce-sims32.cfg ${PKG_SYSCONFDIR}/pce-sims32.cfg

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
