# $NetBSD: Makefile,v 1.2 2002/06/16 21:32:36 wiz Exp $
#

DISTNAME=	donkey
PKGNAME=	edonkey2k-16.16.59
CATEGORIES=	net
MASTER_SITES=	http://www.edonkey2000.com/files/
EXTRACT_SUFX=	.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.edonkey2000.com/
COMMENT=	Yet another P2P file sharing tool

ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-i386

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS=	suse_base>=6.1:../../emulators/${SUSE_DIR_PREFIX}_base
.endif

WRKSRC=		${WRKDIR}
NO_BUILD=	YES
NO_PATCH=	YES
NO_CONFIGURE=	YES
CHECK_SHLIBS=	NO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
