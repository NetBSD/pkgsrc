# $NetBSD: Makefile,v 1.2 1999/02/02 23:14:04 tron Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/26 02:16:00 steve Exp
#

DISTNAME=		xcoral-3.2
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	editors

MAINTAINER=	packages@netbsd.org

USE_X11BASE=	yes
GNU_CONFIGURE=	yes

LIBFILES=	DEPEND README cmd.sc color.sc comments.sc compare-win.sc \
		complete-word.sc describe.sc edir.sc edt.sc example.sc \
		french.sc hack-filename.sc hanoi.sc head.sc html.sc \
		java.sc keydef-ext.sc latex-macros.sc latex.sc \
		man.dtex misc-commands.sc mode-ext.sc mode.sc mouse.sc \
		rcs.sc save.sc sun-keydef.sc title.sc top-ten.sc \
		utilities.sc version.sc window-utilities.sc xcoralrc.lf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xcoral ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/xcoral
.for FILE in ${LIBFILES}
	${INSTALL_DATA} ${WRKSRC}/SmacLib/${FILE} ${PREFIX}/lib/xcoral
.endfor
	@${MKDIR} ${PREFIX}/share/doc/xcoral/HTML/icons
	${CP} -r ${WRKSRC}/Doc/* ${PREFIX}/share/doc/xcoral

.include <../../mk/bsd.pkg.mk>
