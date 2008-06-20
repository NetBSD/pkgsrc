# $NetBSD: Makefile,v 1.7 2008/06/20 01:09:18 joerg Exp $
#

DISTNAME=		vmips-1.3.1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vmips/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vmips.sourceforge.net/
COMMENT=		MIPS R3000 emulator

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin include/vmips ${PKGMANDIR}/man1 share/vmips share/examples/vmips
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

EGDIR=			${PREFIX}/share/examples/vmips
CONF_FILES=		${EGDIR}/vmipsrc ${PKG_SYSCONFDIR}/vmipsrc

USE_LANGUAGES=		c c++

.include "../../mk/bsd.pkg.mk"
