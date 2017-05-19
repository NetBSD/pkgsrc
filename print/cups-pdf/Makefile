# $NetBSD: Makefile,v 1.12 2017/05/19 13:18:18 prlw1 Exp $

COMMENT=		PDF backend for CUPS

DISTNAME=		cups-pdf-2.6.1
PKGREVISION=		7
CATEGORIES=		print

HOMEPAGE=		http://www.cups-pdf.de/
MASTER_SITES=		${HOMEPAGE}src/
DISTFILES=		${DISTNAME:S/pdf-/pdf_/}.tar.gz
LICENSE=		gnu-gpl-v2

DEPENDS+=		cups-[0-9]*:../../print/cups

USE_TOOLS+=		perl:run
REPLACE_PERL+=		contrib/cups-pdf-dispatch-0.1/cups-pdf-dispatch

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	pre-configure
SUBST_MESSAGE.fix-paths=Fixing absolute paths
SUBST_FILES.fix-paths=	src/cups-pdf.h extra/cups-pdf.conf
SUBST_SED.fix-paths=	-e 's,CPCONFIG "/etc/,CPCONFIG "${PREFIX}/etc/,'
SUBST_SED.fix-paths+=	-e 's,"/usr/bin/gs","${PREFIX}/bin/gs",'
SUBST_SED.fix-paths+=	-e 's,\#GhostScript /usr/bin/gs,GhostScript ${PREFIX}/bin/gs,'

CONF_FILES+=		${PREFIX}/share/examples/cups/cups-pdf.conf \
			${PKG_SYSCONFDIR}/cups/cups-pdf.conf

INSTALLATION_DIRS+=	${PREFIX}/bin \
			${PREFIX}/libexec/cups/backend \
			${PREFIX}/share/cups/model \
			${PREFIX}/share/examples/cups

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -o src/cups-pdf src/cups-pdf.c

#pre-install:
#	${SUBST_CMD} ${WRKBUILD}/extra/cups-pdf.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cups-pdf \
		${DESTDIR}${PREFIX}/libexec/cups/backend/cups-pdf
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/cups-pdf-dispatch-0.1/cups-pdf-dispatch \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/extra/CUPS-PDF.ppd \
		${DESTDIR}${PREFIX}/share/cups/model/
	${INSTALL_DATA} ${WRKSRC}/extra/cups-pdf.conf \
		${DESTDIR}${PREFIX}/share/examples/cups/
	${INSTALL_DATA} ${WRKSRC}/contrib/cups-pdf-dispatch-0.1/cups-pdf-dispatch.conf \
		${DESTDIR}${PREFIX}/share/examples/cups/
	${INSTALL_DATA} ${WRKSRC}/contrib/cups-pdf-dispatch-0.1/examples/cups-pdf-dispatch-ldap.conf \
		${DESTDIR}${PREFIX}/share/examples/cups/

.include "../../mk/bsd.pkg.mk"
