# $NetBSD: Makefile,v 1.6 2008/03/04 11:02:24 rillig Exp $
#

DISTNAME=		vmips-1.3.1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vmips/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vmips.sourceforge.net/
COMMENT=		MIPS R3000 emulator

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin include/vmips ${PKGMANDIR}/man1 share/vmips share/examples/vmips
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

EGDIR=			${PREFIX}/share/examples/vmips
CONF_FILES=		${EGDIR}/vmipsrc ${PKG_SYSCONFDIR}/vmipsrc

USE_LANGUAGES=		c c++

.include "../../mk/bsd.pkg.mk"
