# $NetBSD: Makefile,v 1.2 2006/03/04 21:30:41 jlam Exp $

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
MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fsh ${PREFIX}/sbin/fs-fsh
	${INSTALL_PROGRAM} ${WRKSRC}/makefs ${PREFIX}/sbin/fs-makefs
	${INSTALL_PROGRAM} ${WRKSRC}/tstfs ${PREFIX}/sbin/fs-tstfs
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/fs-kit

.include "../../mk/bsd.pkg.mk"
