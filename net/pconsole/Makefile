# $NetBSD: Makefile,v 1.1.1.1 2001/06/23 21:52:07 frueauf Exp $
#

DISTNAME=	pconsole-1.0
CATEGORIES=	net
MASTER_SITES=	http://www.heiho.net/pconsole/

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://www.heiho.net/pconsole/
COMMENT=	parallel console tool to access several host via one input tty

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pconsole
	cd ${WRKSRC} && ${INSTALL_DATA} \
	 	README.pconsole ${PREFIX}/share/doc/pconsole

post-patch:
	${MV} ${WRKSRC}/pconsole.sh.in ${WRKSRC}/pconsole.sh.in.pre
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@X11PREFIX@|${X11PREFIX}|g'	\
		< ${WRKSRC}/pconsole.sh.in.pre		\
		> ${WRKSRC}/pconsole.sh.in

.include "../../mk/bsd.pkg.mk"
