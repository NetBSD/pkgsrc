# $NetBSD: Makefile,v 1.34 2010/08/28 21:35:01 wiz Exp $
#

.include "../../net/mldonkey/Makefile.common"

PKGNAME=		${DISTNAME:S/mldonkey/mldonkey-gui/}

COMMENT+=		(GTK interface)

DEPENDS+=		mldonkey-[0-9]*:../../net/mldonkey

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin libexec/mldonkey

.include "options.mk"

do-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/mlgui
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s ../libexec/mldonkey/mlgui mlgui
	${INSTALL_PROGRAM} ${WRKSRC}/mlgui ${DESTDIR}${PREFIX}/libexec/mldonkey
	${INSTALL_PROGRAM} ${WRKSRC}/mlguistarter \
		${DESTDIR}${PREFIX}/libexec/mldonkey
	${INSTALL_PROGRAM} ${WRKSRC}/mlnet+gui \
		${DESTDIR}${PREFIX}/libexec/mldonkey

.include "../../mk/bsd.pkg.mk"
