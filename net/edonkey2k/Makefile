# $NetBSD: Makefile,v 1.11 2005/06/17 03:50:24 jlam Exp $
#

DISTNAME=	donkey
PKGNAME=	edonkey2k-16.16.59
CATEGORIES=	net
MASTER_SITES=	http://www.edonkey2000.com/files/
EXTRACT_SUFX=	.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.edonkey2000.com/
COMMENT=	Yet another P2P file sharing tool

ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-i386

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	suse_base>=6.1:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=	suse_compat>=6.1:../../emulators/${SUSE_DIR_PREFIX}_compat
.endif

WRKSRC=		${WRKDIR}
NO_BUILD=	YES
NO_CONFIGURE=	YES
CHECK_SHLIBS=	NO

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
