# $NetBSD: Makefile,v 1.2 2003/07/28 15:20:37 jschauma Exp $
#

DISTNAME=	overnet0.48.2
PKGNAME=	overnet-0.48.2
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}files/

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.overnet.com/
COMMENT=	Peer-to-peer file sharing client (binary pkg)

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=	suse_compat>=7.3:../../emulators/${SUSE_DIR_PREFIX}_compat
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/overnet
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/overnet
	${INSTALL_DATA_DIR} ${PREFIX}/share/overnet
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/overnet
	@# keep modes, as it doesn't work unless contact.dat is executable
	${CP} -p ${WRKSRC}/contact.dat ${PREFIX}/share/examples/overnet
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/overnet

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
