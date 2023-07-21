# $NetBSD: Makefile,v 1.16 2023/07/21 09:32:36 nia Exp $

.include "Makefile.common"

COMMENT=	Fast gameboy emulator (X11 version)

CONFIGURE_ARGS+=	--with-x

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man6
INSTALLATION_DIRS+=	share/doc/gnuboy
INSTALLATION_DIRS+=	share/examples/gnuboy

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xgnuboy ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/etc/sample.rc \
		${DESTDIR}${PREFIX}/share/examples/gnuboy/
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/docs/* \
		${DESTDIR}${PREFIX}/share/doc/gnuboy/
	${INSTALL_MAN} ${FILESDIR}/xgnuboy.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/xgnuboy.6

BUILDLINK_DEPMETHOD.libXt?=	build

.include "options.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
