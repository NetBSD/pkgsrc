# $NetBSD: Makefile,v 1.1 1998/05/26 22:07:19 tron Exp $
#

DISTNAME=       dialog-0.6z
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/shell

MAINTAINER=	lamj@stat.cmu.edu

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

NO_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		dialog.1

post-install:
	@${MKDIR} ${PREFIX}/share/examples/dialog
.for file in checklist guage infobox inputbox menubox msgbox radiolist textbox yesno
	@${SED} "s,\.\./dialog,${PREFIX}/bin/dialog,g" \
		${WRKSRC}/samples/${file} > ${WRKSRC}/samples/${file}.sed
	@${INSTALL_SCRIPT} ${WRKSRC}/samples/${file}.sed \
		${PREFIX}/share/examples/dialog/${file}
	@${RM} ${WRKSRC}/samples/${file}.sed
.endfor

.include <../../mk/bsd.pkg.mk>
