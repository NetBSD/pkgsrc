# $NetBSD: Makefile,v 1.1 1998/09/05 20:19:16 frueauf Exp $
#

DISTNAME=	zircon-1.18.180
CATEGORIES=	net
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://catless.ncl.ac.uk/Programs/Zircon/

DEPENDS+=	tk-8.0p2:../../x11/tk80

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
