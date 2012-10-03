# $NetBSD: Makefile,v 1.17 2012/10/03 00:02:45 asau Exp $
#

DISTNAME=		tik-0.90
PKGREVISION=		2
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tik/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tik.sourceforge.net/
COMMENT=		Tcl/Tk AOL Instant Messenger client

WRKSRC=			${WRKDIR}/tik
NO_BUILD=		yes
USE_TOOLS+=		pax wish:run

REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	.*sh
REPLACE.wish.new=	${WISH}
REPLACE_FILES.wish=	tik.tcl

TIKDIR=			${PREFIX}/libexec/tik
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${TIKDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tik.tcl ${DESTDIR}${TIKDIR}
	${LN} -s ${TIKDIR}/tik.tcl ${DESTDIR}${PREFIX}/bin/tik
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
		${DESTDIR}${TIKDIR}
	cd ${WRKSRC} && \
		pax -rw components ${DESTDIR}${TIKDIR} && \
		pax -rw media ${DESTDIR}${TIKDIR} && \
		pax -rw packages ${DESTDIR}${TIKDIR} && \
		pax -rw strs ${DESTDIR}${TIKDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/tik
	cd ${WRKSRC}/doc && pax -rw . ${DESTDIR}${PREFIX}/share/doc/tik
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/tik
	${INSTALL_DATA} \
		${WRKSRC}/example.awayrc \
		${WRKSRC}/example.pkgrc \
		${WRKSRC}/example.tikpre \
		${WRKSRC}/example.tikrc \
		${WRKSRC}/example.tikstrs \
		${DESTDIR}${PREFIX}/share/examples/tik

.include "../../mk/bsd.pkg.mk"
