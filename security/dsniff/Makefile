# $NetBSD: Makefile,v 1.24 2005/03/22 01:07:07 wiz Exp $

.include "Makefile.common"

PKGREVISION=	4
COMMENT=	Password sniffer (webspy)

DEPENDS+=	dsniff-nox11-[0-9]*:../../security/dsniff-nox11

USE_X11=	yes
BUILD_TARGET=	libmissing.a webspy

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webspy ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/webspy.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
