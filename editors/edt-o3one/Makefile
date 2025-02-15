# $NetBSD: Makefile,v 1.2 2025/02/15 15:32:45 wiz Exp $

DISTNAME=	edtdist_20161222
PKGNAME=	${DISTNAME:S/dist_/-o3one-/}
CATEGORIES=	editors
MASTER_SITES=	http://www.o3one.org/downloads/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.o3one.org/edt.html
COMMENT=	Text editor from VMS
LICENSE=	gnu-gpl-v2

MAKE_FILE=	makefile
BUILD_TARGET=	edt

INSTALLATION_DIRS=	bin share/doc/edt-o3one

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/edt ${DESTDIR}${PREFIX}/bin/edt-o3one
	${INSTALL_DATA} ${WRKSRC}/edt.hlp ${DESTDIR}${PREFIX}/share/doc/edt-o3one

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
