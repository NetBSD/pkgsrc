# $NetBSD: Makefile,v 1.5 2007/06/14 18:39:05 gdt Exp $

DISTNAME=	fs-kit-0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nobius.org/~dbg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nobius.org/~dbg/
COMMENT=	User-level filesystem testing kit

LICENSE=	fs-kit-license
RESTRICTED=		No commercial use.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/fs-kit

CFLAGS+=	-Dunix=1
MAKE_FILE=	makefile

INSTALLATION_DIRS=	sbin share/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fsh ${PREFIX}/sbin/fs-fsh
	${INSTALL_PROGRAM} ${WRKSRC}/makefs ${PREFIX}/sbin/fs-makefs
	${INSTALL_PROGRAM} ${WRKSRC}/tstfs ${PREFIX}/sbin/fs-tstfs
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/fs-kit

.include "../../mk/bsd.pkg.mk"
