# $NetBSD: Makefile,v 1.4 2010/01/29 23:54:31 joerg Exp $

DISTNAME=	xplot-0.90.8
PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://acert.ir.bbn.com/downloads/acert-geospatial/
HOMEPAGE=	http://www.xplot.org/

MAINTAINER=	gdt@NetBSD.org
COMMENT=	Plotting program (development snapshot)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	yes
GNU_CONFIGURE=	yes

DOCFILES=	ANNOUNCE README README.tcp_plots \
		demo.0 demo.1 demo.2 demo.3 demo.4 demo.5 demo.6 demo.7

INSTALLATION_DIRS+=	share/doc/xplot
INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 \

post-install:
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/share/doc/xplot
.endfor

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
