# $NetBSD: Makefile,v 1.1.1.1 2005/11/20 13:30:03 rillig Exp $
#

DISTNAME=		vmips-1.3.1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vmips/}

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://vmips.sourceforge.net/
COMMENT=		MIPS R3000 emulator

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
INSTALLATION_DIRS=	bin include/vmips man/man1 share/vmips share/examples/vmips
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR:Q}

EGDIR=			${PREFIX}/share/examples/vmips
CONF_FILES=		${EGDIR}/vmipsrc ${PKG_SYSCONFDIR}/vmipsrc

.include "../../mk/bsd.pkg.mk"
