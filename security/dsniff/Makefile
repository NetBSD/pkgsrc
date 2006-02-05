# $NetBSD: Makefile,v 1.27 2006/02/05 23:10:43 joerg Exp $

.include "Makefile.common"

PKGREVISION=	5
COMMENT=	Password sniffer (webspy)

DEPENDS+=	dsniff-nox11-[0-9]*:../../security/dsniff-nox11

BUILD_TARGET=	libmissing.a webspy

INSTALLATION_DIRS+=	sbin man/man8

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webspy ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/webspy.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
