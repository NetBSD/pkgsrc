# $NetBSD: Makefile,v 1.1.1.1 2000/12/15 00:36:28 wiz Exp $
#

DISTNAME=	zircon-1.18.245
CATEGORIES=	chat
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://catless.ncl.ac.uk/Programs/Zircon/

DEPENDS+=	tk-8.3.2:../../x11/tk

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
