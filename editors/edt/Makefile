# $NetBSD: Makefile,v 1.4 2020/01/18 23:30:44 rillig Exp $

DISTNAME=	edt_1.9
PKGNAME=	${DISTNAME:C:_:-:}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=edt-text-editor/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://edt-text-editor.sourceforge.net/
COMMENT=	Text editor which emulates the VAX VMS EDT editor
LICENSE=	gnu-lgpl-v2.1

MAKE_FILE=		makefile
INSTALLATION_DIRS=	bin share/doc/edt share/examples/edt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/edt ${DESTDIR}${PREFIX}/bin/edt
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DESTDIR}${PREFIX}/share/doc/edt
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DESTDIR}${PREFIX}/share/doc/edt
	${INSTALL_DATA} ${WRKSRC}/edt_keypad_*.xml ${DESTDIR}${PREFIX}/share/examples/edt

.include "../../mk/bsd.pkg.mk"
