# $NetBSD: Makefile,v 1.4 1999/07/06 08:04:14 jlam Exp $
#

DISTNAME=       dialog-0.6z
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_SUNSITE:=utils/shell/}

MAINTAINER=	jlam@netbsd.org

DEPENDS+=	ncurses-4.2:../../devel/ncurses

NO_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dialog
.for file in checklist guage infobox inputbox menubox msgbox radiolist textbox yesno
	${SED} "s,\.\./dialog,${PREFIX}/bin/dialog,g" \
		${WRKSRC}/samples/${file} > ${WRKSRC}/samples/${file}.tmp
	${INSTALL_SCRIPT} ${WRKSRC}/samples/${file}.tmp \
		${PREFIX}/share/examples/dialog/${file}
	${RM} ${WRKSRC}/samples/${file}.tmp
.endfor

.include "../../mk/bsd.pkg.mk"
