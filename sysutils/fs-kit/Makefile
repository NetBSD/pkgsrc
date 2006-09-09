# $NetBSD: Makefile,v 1.3 2006/09/09 02:46:08 obache Exp $

DISTNAME=	fs-kit-0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nobius.org/~dbg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nobius.org/~dbg/
COMMENT=	User-level filesystem testing kit

LICENSE=	fs-kit-license

WRKSRC=		${WRKDIR}/fs-kit

CFLAGS+=	-Dunix=1
MAKE_FILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fsh ${PREFIX}/sbin/fs-fsh
	${INSTALL_PROGRAM} ${WRKSRC}/makefs ${PREFIX}/sbin/fs-makefs
	${INSTALL_PROGRAM} ${WRKSRC}/tstfs ${PREFIX}/sbin/fs-tstfs
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/fs-kit

.include "../../mk/bsd.pkg.mk"
