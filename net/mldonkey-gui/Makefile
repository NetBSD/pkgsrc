# $NetBSD: Makefile,v 1.7 2005/10/06 11:51:13 wiz Exp $
#

.include "../../net/mldonkey/Makefile.common"

PKGNAME=		${DISTNAME:S/mldonkey/mldonkey-gui/}
COMMENT+=		(GTK interface)

DEPENDS+=		mldonkey-[0-9]*:../../net/mldonkey

PRINT_PLIST_AWK+=	/^@dirrm libexec\/mldonkey$$/ \
				{ print "@comment in mldonkey: " $$0; next }

INSTALLATION_DIRS=	bin

.include "options.mk"

do-install:
	${RM} -f ${PREFIX}/bin/mlgui
	cd ${PREFIX}/bin && ${LN} -s ../libexec/mldonkey/mlgui mlgui
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/mldonkey
	${INSTALL_PROGRAM} ${WRKSRC}/mlchat ${PREFIX}/libexec/mldonkey
	${INSTALL_PROGRAM} ${WRKSRC}/mlgui ${PREFIX}/libexec/mldonkey
	${INSTALL_PROGRAM} ${WRKSRC}/mlguistarter ${PREFIX}/libexec/mldonkey
	${INSTALL_PROGRAM} ${WRKSRC}/mlim ${PREFIX}/libexec/mldonkey
	${INSTALL_PROGRAM} ${WRKSRC}/mlnet+gui ${PREFIX}/libexec/mldonkey

.include "../../mk/bsd.pkg.mk"
