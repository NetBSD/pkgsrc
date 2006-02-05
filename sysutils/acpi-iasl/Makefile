# $NetBSD: Makefile,v 1.7 2006/02/05 23:10:48 joerg Exp $
#

DISTNAME=	acpica-unix-${ACPI_IASL_VERSION}
PKGNAME=	acpi-iasl-${ACPI_IASL_VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.intel.com/technology/iapc/acpi/downloads/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.intel.com/technology/iapc/acpi/downloads.htm
COMMENT=	Compiler of Intel ACPI CA - Unix Build Environment

ACPI_IASL_VERSION=	20060113

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin share/doc/acpi-iasl

USE_TOOLS+=	bison gm4 gmake

do-build:
	@cd ${WRKSRC}/compiler && ${MAKE_PROGRAM}
	@cd ${WRKSRC}/tools/acpisrc && ${MAKE_PROGRAM}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/compiler/iasl ${PREFIX}/bin/acpi-iasl
	${INSTALL_PROGRAM} ${WRKSRC}/tools/acpisrc/acpisrc ${PREFIX}/bin/acpisrc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/acpi-iasl
	${INSTALL_DATA} ${FILESDIR}/LICENSE ${PREFIX}/share/doc/acpi-iasl

.include "../../mk/bsd.pkg.mk"
