# $NetBSD: Makefile,v 1.8 2008/03/03 01:10:05 jlam Exp $
#

DISTNAME=	arka-0.11
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://bioinformatics.org/genpak/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hdp@cs.nmsu.edu
HOMEPAGE=	http://www.bioinformatics.org/genpak/
COMMENT=	Graphic interface for the programs from the GP package

DEPENDS+=	gp-[0-9]*:../../biology/gp

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=	xdg-1.1

CONF_FILES=	${PREFIX}/share/examples/arka/arkarc ${PKG_SYSCONFDIR}/arkarc
CPPFLAGS+=	-DARKA_GLOBAL=\"${PKG_SYSCONFDIR}/arkarc\"
CPPFLAGS+=	-DARKA_PROGRAMS=\"${PKG_SYSCONFDIR}/arkarc\"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
USE_TOOLS+=		gunzip

post-build:
	cd ${WRKSRC} && ${GUNZIP_CMD} arka.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arka ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/arka.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for f in arka_16x16.xpm arka_32x32.xpm
	${INSTALL_DATA} ${WRKSRC}/icons/${f} ${DESTDIR}${PREFIX}/share/pixmaps
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/arka
.for f in CHANGES.TXT INSTALL.TXT LICENSE.TXT README.TXT TODO.TXT
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/arka
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/arka
	${INSTALL_DATA} ${WRKSRC}/arkarc ${DESTDIR}${PREFIX}/share/examples/arka

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
