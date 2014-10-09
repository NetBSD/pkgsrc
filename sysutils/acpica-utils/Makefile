# $NetBSD: Makefile,v 1.8 2014/10/09 14:06:56 wiz Exp $
#

DISTNAME=	acpica-unix-${ACPICA_UTILS_VERSION}
PKGNAME=	acpica-utils-${ACPICA_UTILS_VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.acpica.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.acpica.org/
COMMENT=	Intel ACPI CA Unix utilities

ACPICA_UTILS_VERSION=	20090625

INSTALLATION_DIRS=	bin share/doc/acpica-utils

USE_TOOLS+=	bison flex gm4 gmake

LICENSE=	gnu-gpl-v2 # OR intel-acpica-license
# According to http://www.acpica.org/documentation/faq.php:
#   "Under what licensing is the ACPICA source released?
#      ACPICA can be licensed under the GNU General Public License or via a
#      separate license that may be more favorable to commercial OSVs. Please
#      see the source code license header for specifics.

# Don't have sem_timedwait()
CFLAGS.NetBSD+=	-DACPI_USE_ALTERNATE_TIMEOUT
CFLAGS.DragonFly+=	-DACPI_USE_ALTERNATE_TIMEOUT

do-build:
	cd ${WRKSRC}/tools/acpiexec && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}
	cp -f ${WRKSRC}/tools/acpiexec/acpiexec ${WRKSRC}
	cd ${WRKSRC}/tools/acpiexec && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} clean
	cd ${WRKSRC}/compiler && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}
	cd ${WRKSRC}/tools/acpisrc && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}
	cd ${WRKSRC}/tools/acpixtract && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/compiler/iasl \
		${DESTDIR}${PREFIX}/bin/iasl
	ln -s iasl ${DESTDIR}${PREFIX}/bin/acpi-iasl
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
