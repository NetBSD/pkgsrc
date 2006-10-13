# $NetBSD: Makefile,v 1.42 2006/10/13 14:41:39 dsainty Exp $

DISTNAME=	exmh-2.6.3
PKGREVISION=	1
CATEGORIES=	mail tk
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/exmh/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.beedub.com/exmh/
COMMENT=	X11/TK based mail reader front end to MH

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	nmh>=1.0:../../mail/nmh
DEPENDS+=	metamail>=2.7:../../mail/metamail

.include "../../mk/bsd.prefs.mk"

DIST_SUBDIR=	${PKGNAME_NOREV}

WISH=		wish
TCLSH=		tclsh

# Additionally, exmh will use the following packages if present:
# lang/expect
# textproc/glimpse
# security/gnupg
# security/pgp
# mail/faces
# audio/rplay

.include "../../mk/x11.buildlink3.mk"

do-build:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} TCLSH=${TCLSH} \
		WISH=${PREFIX}/bin/${WISH} WRKSRC=${WRKSRC} \
		FILESDIR=${FILESDIR} ${SH} ${FILESDIR}/build

do-install:
	${INSTALL_MAN} ${WRKSRC}/exmh.l ${PREFIX}/man/man1/exmh.1
	for binfile in exmh-async exmh-bg exmh ftp.expect; do \
		${INSTALL_PROGRAM} ${WRKSRC}/$$binfile ${PREFIX}/bin; \
	done
	vers=`sed -ne 's/^set vers \(.*\)/\1/p' ${WRKSRC}/exmh.install`; \
	${INSTALL_DATA_DIR} ${PREFIX}/lib/exmh-$${vers}; \
	${INSTALL_DATA_DIR} ${PREFIX}/lib/exmh-$${vers}/html; \
	for libfile in \
			${WRKSRC}/lib/PgpDecryptExpect \
			${WRKSRC}/lib/*.tcl ${WRKSRC}/lib/*.bitmap \
			${WRKSRC}/lib/*.ppm ${WRKSRC}/lib/help.* \
			${WRKSRC}/lib/tclIndex ${WRKSRC}/lib/app-defaults \
			${WRKSRC}/lib/app-defaults-* ${WRKSRC}/lib/*.mask \
			${WRKSRC}/lib/*.exp ${WRKSRC}/lib/mime.types \
			${WRKSRC}/lib/*.au ${WRKSRC}/lib/*.gif; do \
		${INSTALL_DATA} $$libfile ${PREFIX}/lib/exmh-$${vers}; \
	done; \
	for hfile in ${WRKSRC}/lib/html/*; do \
		${INSTALL_DATA} $$hfile ${PREFIX}/lib/exmh-$${vers}/html; \
	done

.include "../../mk/bsd.pkg.mk"
