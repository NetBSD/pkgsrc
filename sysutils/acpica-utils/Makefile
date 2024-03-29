# $NetBSD: Makefile,v 1.17 2023/10/02 11:19:26 rhialto Exp $
#

DISTNAME=	acpica-unix2-20160930
PKGNAME=	${DISTNAME:S/-unix2-/-utils-/}
PKGREVISION=	2
CATEGORIES=	sysutils devel
MASTER_SITES=	https://acpica.org/sites/acpica/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.acpica.org/
COMMENT=	Intel ACPI CA Unix utilities
LICENSE=	modified-bsd OR gnu-gpl-v2

TESTS_DISTNAME=	${DISTNAME:S/acpica-unix2-/acpitests-unix-/}
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	${TESTS_DISTNAME}${EXTRACT_SUFX}

USE_TOOLS+=	bison flex gm4 gmake bash

REPLACE_BASH+=	tests/aslts.sh
REPLACE_BASH+=	tests/aslts/bin/Do
REPLACE_BASH+=	tests/aslts/bin/asltsdiffres
REPLACE_BASH+=	tests/aslts/bin/asltsrun
REPLACE_BASH+=	tests/aslts/bin/bugstate/bdemosconc
REPLACE_BASH+=	tests/aslts/bin/bugstate/bdemossum
REPLACE_BASH+=	tests/aslts/bin/bugstate/bdemostabs
REPLACE_BASH+=	tests/aslts/bin/bugstate/parsebuglist
REPLACE_BASH+=	tests/aslts/bin/common
REPLACE_BASH+=	tests/aslts/bin/diffproc
REPLACE_BASH+=	tests/aslts/bin/settings
REPLACE_BASH+=	tests/templates/templates.sh

post-extract:
	${RUN}rm -rf ${WRKSRC}/tests
	${RUN}mv ${WRKDIR}/${TESTS_DISTNAME}/tests ${WRKSRC}

do-test:
# ACPICA Tests rely on non-zero exit
## ASL tests
	cd ${WRKSRC}/tests && ./aslts.sh -u
## API tests
	cd ${WRKSRC}/tests/aapits && gmake
	cd ${WRKSRC}/tests/aapits/asl && \
	ASL=${WRKSRC}/generate/unix/bin/iasl gmake
# This one needs to be fixed
#	cd ${WRKSRC}/tests/aapits/bin && ./aapitsrun
## Template tests
# This test is broken too
#	cd ${WRKSRC}/tests/templates && gmake

.include "../../mk/compiler.mk"

# XXX
.if !empty(CC_VERSION:Mgcc-[89]*)
CFLAGS+=	-Wno-error=format-truncation
.endif
.if !empty(CC_VERSION:Mgcc-9*)
CFLAGS+=	-Wno-error=format-overflow \
		-Wno-error=stringop-truncation
.endif
.if !empty(CC_VERSION:Mgcc-1[02]*)
CFLAGS+=	-Wno-error=format-overflow \
		-Wno-error=format-truncation \
		-Wno-error=stringop-truncation
.endif
.if !empty(CC_VERSION:Mgcc-12*)
CFLAGS+=	-Wno-error=dangling-pointer
.endif

.include "../../mk/bsd.pkg.mk"
