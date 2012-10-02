# $NetBSD: Makefile,v 1.57 2012/10/02 17:11:47 tron Exp $
#

.include "../../net/mldonkey/Makefile.common"

PKGNAME=		${DISTNAME:S/mldonkey/mldonkey-gui/}
PKGREVISION=		1

COMMENT+=		(GTK interface)

DEPENDS+=		mldonkey-[0-9]*:../../net/mldonkey

USE_TOOLS+=		pkg-config autoconf

INSTALLATION_DIRS=	bin libexec/mldonkey

CONFIGURE_ARGS+=	--enable-gui=newgui2
CONFIGURE_ARGS+=	--disable-option-checking

pre-configure:
	cd ${WRKSRC}/config && autoconf

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
BUILDLINK_API_DEPENDS.lablgtk+=	lablgtk>=2.16.0
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
