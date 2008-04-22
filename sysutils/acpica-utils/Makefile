# $NetBSD: Makefile,v 1.1.1.1 2008/04/22 20:22:58 xtraeme Exp $
#

DISTNAME=	acpica-unix-${ACPICA_UTILS_VERSION}
PKGNAME=	acpica-utils-${ACPICA_UTILS_VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://www.acpica.org/download/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.acpica.org/
COMMENT=	Intel ACPI CA Unix utilities

ACPICA_UTILS_VERSION=	20080321

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin share/doc/acpica-utils

USE_TOOLS+=	bison flex gm4 gmake

do-build:
	@cd ${WRKSRC}/tools/acpiexec && ${MAKE_PROGRAM}
	@cp -f ${WRKSRC}/tools/acpiexec/acpiexec ${WRKSRC}
	@cd ${WRKSRC}/tools/acpiexec && ${MAKE_PROGRAM} clean
	@cd ${WRKSRC}/compiler && ${MAKE_PROGRAM}
	@cd ${WRKSRC}/tools/acpisrc && ${MAKE_PROGRAM}
	@cd ${WRKSRC}/tools/acpixtract && ${MAKE_PROGRAM}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/compiler/iasl \
		${DESTDIR}${PREFIX}/bin/acpi-iasl
	${INSTALL_PROGRAM} ${WRKSRC}/acpiexec ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/acpixtract/acpixtract \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/acpisrc/acpisrc \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/acpica-utils
	${INSTALL_DATA} ${FILESDIR}/LICENSE \
		${DESTDIR}${PREFIX}/share/doc/acpica-utils

.include "../../mk/bsd.pkg.mk"
