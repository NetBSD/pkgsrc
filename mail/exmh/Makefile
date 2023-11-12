# $NetBSD: Makefile,v 1.60 2023/11/12 13:22:34 wiz Exp $

DISTNAME=	exmh-2.7.2
PKGREVISION=	10
CATEGORIES=	mail tk
MASTER_SITES=	ftp://ftp.tcl.tk/pub/tcl/exmh/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.beedub.com/exmh/
COMMENT=	X11/TK based mail reader front end to MH

DEPENDS+=	nmh>=1.0:../../mail/nmh
DEPENDS+=	metamail>=2.7:../../mail/metamail

USE_TOOLS+=	tclsh
USE_TOOLS+=	wish:run

.include "../../mk/bsd.prefs.mk"

DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 lib/${PKGNAME_NOREV}/html

# Additionally, exmh will use the following packages if present:
# lang/expect
# textproc/glimpse
# security/gnupg
# security/pgp
# mail/faces
# audio/rplay

do-build:
	cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} TCLSH=${TCLSH:Q} \
		WISH=${WISH:Q} WRKSRC=${WRKSRC} \
		FILESDIR=${FILESDIR} ${SH} ${FILESDIR}/build

do-install:
	${INSTALL_MAN} ${WRKSRC}/exmh.l \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/exmh.1
	for binfile in exmh-async exmh-bg exmh-strip exmh ftp.expect; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$binfile ${DESTDIR}${PREFIX}/bin; \
	done
	for libfile in \
			${WRKSRC}/lib/PgpDecryptExpect \
			${WRKSRC}/lib/*.tcl ${WRKSRC}/lib/*.bitmap \
			${WRKSRC}/lib/*.ppm ${WRKSRC}/lib/help.* \
			${WRKSRC}/lib/tclIndex ${WRKSRC}/lib/app-defaults \
			${WRKSRC}/lib/app-defaults-* ${WRKSRC}/lib/*.mask \
			${WRKSRC}/lib/*.exp ${WRKSRC}/lib/mime.types \
			${WRKSRC}/lib/*.au ${WRKSRC}/lib/*.gif; do \
		${INSTALL_DATA} $$libfile \
			${DESTDIR}${PREFIX}/lib/${PKGNAME_NOREV}; \
	done
	for hfile in ${WRKSRC}/lib/html/*; do \
		${INSTALL_DATA} $$hfile \
			${DESTDIR}${PREFIX}/lib/${PKGNAME_NOREV}/html; \
	done

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
