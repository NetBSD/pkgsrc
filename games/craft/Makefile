# $NetBSD: Makefile,v 1.3 1999/08/11 22:01:46 tron Exp $

DISTNAME=	craftcc35
PKGNAME=	craft-3.5
CATEGORIES=	games x11
MASTER_SITES=	ftp://borneo.gmd.de/pub/as/janus/craft/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://borneo.gmd.de/~hua/

WRKSRC=		${WRKDIR}
USE_GMAKE=	yes
USE_X11BASE=	yes

post-extract:
	@find ${WRKSRC} -type f -name '*~' | xargs ${RM} -f

post-patch:
	${RM} -f ${WRKSRC}/hcc/hcc
	${CP} ${WRKSRC}/.windefaults.params ${WRKSRC}/foo
	${SED} -e 's+buttons+${PREFIX}/share/craft/buttons+' <${WRKSRC}/foo> ${WRKSRC}/.windefaults.params
	${CP} ${WRKSRC}/win.hc ${WRKSRC}/foo
	${SED} -e 's+@PREFIX@+${PREFIX}+' <${WRKSRC}/foo> ${WRKSRC}/win.hc
	${CP} ${WRKSRC}/setupedit.hc ${WRKSRC}/foo
	${SED} -e 's+@PREFIX@+${PREFIX}+' <${WRKSRC}/foo> ${WRKSRC}/setupedit.hc
	${CP} ${WRKSRC}/option_menu.hc ${WRKSRC}/foo
	${SED} -e 's+@PREFIX@+${PREFIX}+' <${WRKSRC}/foo> ${WRKSRC}/option_menu.hc
	${CP} ${WRKSRC}/craft_def.h ${WRKSRC}/foo
	${SED} -e 's+@PREFIX@+${PREFIX}+' <${WRKSRC}/foo> ${WRKSRC}/craft_def.h
	${RM} -f ${WRKSRC}/foo

.include "../../mk/bsd.pkg.mk"
