# $NetBSD: Makefile,v 1.30 2008/10/01 08:43:09 apb Exp $

.include "Makefile.common"

PKGREVISION=	6
COMMENT=	Password sniffer (webspy)

DEPENDS+=	dsniff-nox11-[0-9]*:../../security/dsniff-nox11

BUILD_TARGET=	libmissing.a webspy

INSTALLATION_DIRS+=	sbin man/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webspy ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/webspy.8 ${PREFIX}/${PKGMANDIR}/man8

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
