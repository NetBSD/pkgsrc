# $NetBSD: Makefile,v 1.55 2012/09/07 19:17:21 adam Exp $
#

.include "../../net/mldonkey/Makefile.common"

PKGNAME=		${DISTNAME:S/mldonkey/mldonkey-gui/}
PKGREVISION=		4

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
# 2.6.0 is the first ~stable version (for mldonkey)
BUILDLINK_API_DEPENDS.lablgtk+=	lablgtk>=2.6.0
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
