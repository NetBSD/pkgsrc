# $NetBSD: Makefile,v 1.6 2003/09/06 04:56:28 itojun Exp $
#

DISTNAME=	p0f
PKGNAME=	p0f-2.0.1
CATEGORIES=	security net
MASTER_SITES=	http://lcamtuf.coredump.cx/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dawszy@arhea.net
COMMENT=	Passive OS fingerprinting tool
HOMEPAGE=	http://lcamtuf.coredump.cx/p0f.shtml

USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes

CFLAGS+=	-DSYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\\\"\"
CONF_FILES=	${PREFIX}/share/examples/p0f/p0f.fp ${PKG_SYSCONFDIR}/p0f.fp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/p0f ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/p0f.README
	${INSTALL_DATA} ${WRKSRC}/p0frep ${PREFIX}/share/doc/p0frep
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/p0f
	${INSTALL_DATA} ${WRKSRC}/p0f.fp ${PREFIX}/share/examples/p0f

.include "../../mk/bsd.pkg.mk"
