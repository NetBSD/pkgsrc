# $NetBSD: Makefile,v 1.1.1.2 2003/07/28 15:02:25 jschauma Exp $

DISTNAME=	overnet0.44
PKGNAME=	overnet-0.44
CATEGORIES=	net
MASTER_SITES=	http://www.overnet.com/files/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.overnet.com
COMMENT=	File-sharing program based on edonkey2k

ONLY_FOR_PLATFORM=      NetBSD-*-i386 Linux-*-i386

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=       suse_base>=6.1:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=       suse_compat>=6.1:../../emulators/${SUSE_DIR_PREFIX}_compat
.endif

NO_BUILD=	YES
NO_CONFIGURE=	YES
NO_PATCH=	YES
WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/overnet
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/overnet
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/overnet
	${INSTALL_DATA} ${WRKSRC}/contact.dat 	\
		${PREFIX}/share/examples/overnet/contact.dat
	${INSTALL_PROGRAM} ${WRKDIR}/overnet_s_44 ${PREFIX}/bin/overnet

.include "../../mk/bsd.pkg.mk"
