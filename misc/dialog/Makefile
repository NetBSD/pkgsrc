# $NetBSD: Makefile,v 1.3 1999/04/15 20:39:44 tron Exp $
#

DISTNAME=       dialog-0.6z
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_SUNSITE:=utils/shell/}

MAINTAINER=	lamj@stat.cmu.edu

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

NO_CONFIGURE=	yes
USE_GMAKE=	yes

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
