# $NetBSD: Makefile,v 1.7 2000/11/02 03:25:33 wiz Exp $
#

DISTNAME=       dialog-0.6z
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_SUNSITE:=utils/shell/}

MAINTAINER=	jlam@netbsd.org

NO_CONFIGURE=	# defined
USE_GMAKE=	# defined
USE_CURSES=	# defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dialog
.for file in checklist guage infobox inputbox menubox msgbox radiolist textbox yesno
	${SED} "s,\.\./dialog,${PREFIX}/bin/dialog,g" \
		${WRKSRC}/samples/${file} > ${WRKSRC}/samples/${file}.tmp
	${INSTALL_SCRIPT} ${WRKSRC}/samples/${file}.tmp \
		${PREFIX}/share/examples/dialog/${file}
	${RM} ${WRKSRC}/samples/${file}.tmp
.endfor

.include "../../mk/bsd.prefs.mk"

.if defined(NEED_NCURSES) && ${NEED_NCURSES} == "YES"
MAKE_ENV+=	HAVE_TRUE_NCURSES=true
.endif

.include "../../mk/bsd.pkg.mk"
