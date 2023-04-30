# $NetBSD: Makefile,v 1.3 2023/04/30 20:18:08 nikita Exp $

.include "../../lang/chicken5/Makefile.common"

PKGNAME=	${DISTNAME:S/chicken/chicken5-boot/}

BUILD_TARGET=		boot-chicken
WRKSRC=			${WRKDIR}/chicken-${PKGVERSION_NOREV}
INSTALLATION_DIRS+=	libexec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chicken-boot ${DESTDIR}${PREFIX}/libexec/chicken-bootstrap

.include "../../mk/bsd.pkg.mk"
