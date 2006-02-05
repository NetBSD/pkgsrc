# $NetBSD: Makefile,v 1.18 2006/02/05 23:09:13 joerg Exp $

DISTNAME=	craftcc35
PKGNAME=	craft-3.5
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	ftp://set.gmd.de/pub/as/janus/craft/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://set.gmd.de/~hua/
COMMENT=	Warcraft-like game for X11

WRKSRC=		${WRKDIR}
USE_TOOLS+=	gmake
USE_X11BASE=	yes

.include "../../mk/x11.buildlink3.mk"

post-extract:
	@${FIND} ${WRKSRC} -type f -name '*~' -print | ${XARGS} ${RM} -f
	@${LN} -fs ${FILESDIR}/Makefile ${WRKSRC}
	for FILE in `${FIND} ${WRKSRC} -name "*.hc" -type f -print`; do	\
	  ${ECHO} >>$$FILE "";					\
	done

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
