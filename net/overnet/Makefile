# $NetBSD: Makefile,v 1.10 2005/12/12 14:43:26 joerg Exp $
#

DISTNAME=	overnetclc-1.0.1
PKGNAME=	${DISTNAME:C/clc//}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.zen18864.zen.co.uk/overnet/1.0.1/
DISTFILES=	${DISTNAME}-1.i386_compat.rpm

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.overnet.com/
COMMENT=	Peer-to-peer file sharing client (binary pkg)

BUILD_DEPENDS+=	rpm2pkg-[0-9]*:../../pkgtools/rpm2pkg

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
CHECK_SHLIBS=	no

EVAL_PREFIX=	RPM2PKGDIR=rpm2pkg

.include "../../emulators/suse_linux/Makefile.application"

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=	suse_compat>=7.3:../../emulators/${SUSE_DIR_PREFIX}_compat
.endif

ONLY_FOR_PLATFORM=	*-*-i386

INSTALLATION_DIRS=	bin

do-extract:
	${RPM2PKGDIR}/sbin/rpm2pkg -d ${WRKDIR}				\
		${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/usr/bin/overnetclc ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/overnetclc
.for f in ChangeLog LISEZMOI README
	${INSTALL_DATA} ${WRKDIR}/usr/share/doc/overnetclc/${f}		\
		${PREFIX}/share/doc/overnetclc
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/overnetclc
	${INSTALL_DATA} ${WRKSRC}/usr/share/overnetclc/contact.dat	\
		${PREFIX}/share/overnetclc

.include "../../mk/bsd.pkg.mk"
