# $NetBSD: Makefile,v 1.5 2003/07/21 17:20:12 martti Exp $
#

DISTNAME=	p0f-1.8.3
CATEGORIES=	security net
MASTER_SITES=	http://www.stearns.org/p0f/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dawszy@arhea.net
COMMENT=	Passive OS fingerprinting tool

USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes

CFLAGS+=	-DSYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\\\"\"
CONF_FILES=	${PREFIX}/share/examples/p0f/p0f.fp ${PKG_SYSCONFDIR}/p0f.fp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/p0f ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/p0f.README
	${INSTALL_DATA} ${WRKSRC}/p0frep ${PREFIX}/share/doc/p0frep
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/p0f
	${INSTALL_DATA} ${WRKSRC}/p0f.fp ${PREFIX}/share/examples/p0f

.include "../../mk/bsd.pkg.mk"
