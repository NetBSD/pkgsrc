# $NetBSD: Makefile,v 1.5 2004/12/19 11:14:51 minskim Exp $
#

DISTNAME=	overnetclc-1.0.1
PKGNAME=	${DISTNAME:C/clc//}
CATEGORIES=	net
MASTER_SITES=	http://www.zen18864.zen.co.uk/overnet/1.0.1/
DISTFILES=	${DISTNAME}-1.i386_compat.rpm

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.overnet.com/
COMMENT=	Peer-to-peer file sharing client (binary pkg)

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	# defined
NO_BUILD=	# defined
PLIST_SRC+=	${WRKDIR}/PLIST_DYNAMIC
PLIST_SUBST+=	EMULSUBDIR=${EMULSUBDIR}

RPMFILES=	${DISTFILES}

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=	suse_compat>=7.3:../../emulators/${SUSE_DIR_PREFIX}_compat
.endif

post-install:
	${LN} -fs ../${EMULSUBDIR}/usr/bin/overnetclc ${PREFIX}/bin

no-do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/overnet
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/overnet
	${INSTALL_DATA_DIR} ${PREFIX}/share/overnet
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/overnet
	@# keep modes, as it doesn't work unless contact.dat is executable
	${CP} -p ${WRKSRC}/contact.dat ${PREFIX}/share/examples/overnet
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/overnet

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
