# $NetBSD: Makefile,v 1.35 2024/05/29 16:34:09 adam Exp $

DISTNAME=		cups-pdf-3.0.1
PKGREVISION=		14
CATEGORIES=		print
MASTER_SITES=		${HOMEPAGE}src/
DISTFILES=		${DISTNAME:S/pdf-/pdf_/}.tar.gz

HOMEPAGE=		https://www.cups-pdf.de/
COMMENT=		PDF backend for CUPS
LICENSE=		gnu-gpl-v2

DEPENDS+=		cups-base-[0-9]*:../../print/cups-base

USE_TOOLS+=		perl:run

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths
SUBST_FILES.fix-paths=		src/cups-pdf.h extra/cups-pdf.conf
SUBST_SED.fix-paths=		-e 's,CPCONFIG "/etc/,CPCONFIG "${PREFIX}/etc/,'
SUBST_SED.fix-paths+=		-e 's,"/usr/bin/gs","${PREFIX}/bin/gs",'
SUBST_SED.fix-paths+=		-e 's,\#GhostScript /usr/bin/gs,GhostScript ${PREFIX}/bin/gs,'

CONF_FILES+=		${PREFIX}/share/examples/cups/cups-pdf.conf \
			${PKG_SYSCONFDIR}/cups/cups-pdf.conf

INSTALLATION_DIRS+=	${PREFIX}/libexec/cups/backend \
			${PREFIX}/share/cups/model \
			${PREFIX}/share/examples/cups

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} ${LDFLAGS} ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libcups}/lib \
		-L${BUILDLINK_PREFIX.libcups}/lib \
		-lcups \
		-o src/cups-pdf src/cups-pdf.c

#pre-install:
#	${SUBST_CMD} ${WRKBUILD}/extra/cups-pdf.conf

do-install:
	# cups-pdf backend must be installed as 0700 permission.
	${INSTALL} ${COPY} ${_STRIPFLAG_INSTALL} -o ${BINOWN} -g ${BINGRP} \
		-m 700 ${WRKSRC}/src/cups-pdf \
		${DESTDIR}${PREFIX}/libexec/cups/backend/cups-pdf
	${INSTALL_DATA} ${WRKSRC}/extra/CUPS-PDF_noopt.ppd \
		${DESTDIR}${PREFIX}/share/cups/model/
	${INSTALL_DATA} ${WRKSRC}/extra/CUPS-PDF_opt.ppd \
		${DESTDIR}${PREFIX}/share/cups/model/
	${INSTALL_DATA} ${WRKSRC}/extra/cups-pdf.conf \
		${DESTDIR}${PREFIX}/share/examples/cups/

.include "../../print/libcups/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
