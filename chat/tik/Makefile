# $NetBSD: Makefile,v 1.13 2006/08/26 13:58:17 minskim Exp $
#

DISTNAME=		tik-0.90
PKGREVISION=		2
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tik/}

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://tik.sourceforge.net/
COMMENT=		Tcl/Tk AOL Instant Messenger client

WRKSRC=			${WRKDIR}/tik
NO_BUILD=		yes
USE_TOOLS+=		wish:run

REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	.*sh
REPLACE.wish.new=	${WISH}
REPLACE_FILES.wish=	tik.tcl

TIKDIR=			${PREFIX}/libexec/tik
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${TIKDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tik.tcl ${TIKDIR}
	${LN} -s ${TIKDIR}/tik.tcl ${PREFIX}/bin/tik
	${INSTALL_DATA} \
		${WRKSRC}/balloonhelp.tcl \
		${WRKSRC}/buddylist.tcl \
		${WRKSRC}/buddymgmt.tcl \
		${WRKSRC}/callbacks.tcl \
		${WRKSRC}/chat.tcl \
		${WRKSRC}/configTool.tcl \
		${WRKSRC}/configandpkg.tcl \
		${WRKSRC}/configdir.tcl \
		${WRKSRC}/im.tcl \
		${WRKSRC}/info.tcl \
		${WRKSRC}/popup.tcl \
		${WRKSRC}/prefs.tcl \
		${WRKSRC}/protocol.tcl \
		${WRKSRC}/proxy.tcl \
		${WRKSRC}/sag.tcl \
		${WRKSRC}/sflap.tcl \
		${WRKSRC}/toc.tcl \
		${WRKSRC}/ui.tcl \
		${WRKSRC}/util.tcl \
		${WRKSRC}/version.tcl \
		${WRKSRC}/example.awayrc \
		${WRKSRC}/example.pkgrc \
		${TIKDIR}
	cd ${WRKSRC} && \
		${PAX} -rw components ${TIKDIR} && \
		${PAX} -rw media ${TIKDIR} && \
		${PAX} -rw packages ${TIKDIR} && \
		${PAX} -rw strs ${TIKDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tik
	cd ${WRKSRC}/doc && ${PAX} -rw . ${PREFIX}/share/doc/tik
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tik
	${INSTALL_DATA} \
		${WRKSRC}/example.awayrc \
		${WRKSRC}/example.pkgrc \
		${WRKSRC}/example.tikpre \
		${WRKSRC}/example.tikrc \
		${WRKSRC}/example.tikstrs \
		${PREFIX}/share/examples/tik

.include "../../mk/bsd.pkg.mk"
