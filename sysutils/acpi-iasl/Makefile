# $NetBSD: Makefile,v 1.1.1.1 2004/02/28 17:09:21 uebayasi Exp $
#

DISTNAME=	acpica-unix-${ACPI_IASL_VERSION}
PKGNAME=	acpi-iasl-${ACPI_IASL_VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://www.intel.com/technology/iapc/acpi/downloads/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.intel.com/technology/iapc/acpi/downloads.htm
COMMENT=	Compiler of Intel ACPI CA - Unix Build Environment

DEPENDS+=	bison-[0-9]*:../../devel/bison

ACPI_IASL_VERSION=	20031203

USE_GNU_TOOLS=	make

do-build:
	cd ${WRKSRC}/compiler && ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/compiler/iasl ${LOCALBASE}/bin/acpi-iasl
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/doc/acpi-iasl
	${INSTALL_DATA} ${WRKSRC}/README ${LOCALBASE}/share/doc/acpi-iasl
	${INSTALL_DATA} ${FILESDIR}/LICENSE ${LOCALBASE}/share/doc/acpi-iasl

.include "../../mk/bsd.pkg.mk"
