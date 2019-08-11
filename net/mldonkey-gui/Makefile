# $NetBSD: Makefile,v 1.126 2019/08/11 13:22:11 wiz Exp $

PKGREVISION= 39
.include "../../net/mldonkey/Makefile.common"

PKGNAME=		${DISTNAME:S/mldonkey/mldonkey-gui/}

COMMENT+=		(GTK interface)

DEPENDS+=		mldonkey-[0-9]*:../../net/mldonkey

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin libexec/mldonkey

CONFIGURE_ARGS+=	--enable-gui=newgui2
CONFIGURE_ARGS+=	--disable-option-checking

do-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/mlgui
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s ../libexec/mldonkey/mlgui mlgui
	${INSTALL_PROGRAM} ${WRKSRC}/mlgui ${DESTDIR}${PREFIX}/libexec/mldonkey
	${INSTALL_PROGRAM} ${WRKSRC}/mlguistarter \
		${DESTDIR}${PREFIX}/libexec/mldonkey
	${INSTALL_PROGRAM} ${WRKSRC}/mlnet+gui \
		${DESTDIR}${PREFIX}/libexec/mldonkey

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
# 2.16.0 is the first version that installs in the right location
BUILDLINK_API_DEPENDS.ocaml-lablgtk+=	ocaml-lablgtk>=2.16.0
.include "../../x11/ocaml-lablgtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
