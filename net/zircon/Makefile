# $NetBSD: Makefile,v 1.3 1999/02/03 13:00:18 frueauf Exp $
#

DISTNAME=	zircon-1.18.210
CATEGORIES=	net
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://catless.ncl.ac.uk/Programs/Zircon/

DEPENDS+=	tk-8.0p2:../../x11/tk80

CONFLICTS=	zircon-*

IS_INTERACTIVE=	yes
NO_BUILD=	yes

post-patch:
	@${MV} ${WRKSRC}/installer/unix.tcl ${WRKSRC}/installer/unix.tcl.bak
	@${SED} -e 's|@@@PREFIX@@@|${PREFIX}|g' \
		< ${WRKSRC}/installer/unix.tcl.bak \
		> ${WRKSRC}/installer/unix.tcl

do-install:
	@${ECHO} ""
	@${ECHO} "Please just click <Install> and <Quit> to ensure proper installation."
	@${ECHO} ""
	@( cd ${WRKSRC} && ./installZircon )
	@${MKDIR} ${PREFIX}/share/doc/zircon
.for file in BUGS COPYRIGHT FAQ MANUAL MIRRORS README.ONS README.load README.look README.prefs TODO
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/zircon
.endfor

.include "../../mk/bsd.pkg.mk"
