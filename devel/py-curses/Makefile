# $NetBSD: Makefile,v 1.10 2000/08/21 21:01:30 hubertf Exp $
#

DISTNAME=	cursesmodule-1.5b1
PKGNAME=	py-curses-1.5b1
CATEGORIES=	devel
MASTER_SITES=	ftp://starship.skyport.net/pub/crew/andrich/Unsupported/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://starship.skyport.net/crew/amk/howto/curses/curses.html

DEPENDS+=	python-1.5.2:../../lang/python
DEPENDS+=       ncurses>=4.2:../../devel/ncurses

WRKSRC=		${WRKDIR}/cursesmodule
ALL_TARGET=	default

PYTHON_CONFIGDIR=	${LOCALBASE}/lib/python1.5/config/

.if ${MACHINE_ARCH} == "sparc64"
IGNORE="${PKGNAME} needs dynamic loading"
.endif

do-configure:
	${SED} -e 's%@LOCALBASE@%${LOCALBASE}%g' \
	 ${FILESDIR}/Setup.in \
	 >${WRKSRC}/Setup.in
	( cd ${WRKSRC} ;\
	  ${MAKE} -f Makefile.pre.in boot)

do-install:
	${INSTALL_DATA} ${WRKSRC}/cursesmodule.so ${LOCALBASE}/lib/python1.5/lib-dynload

.include "../../mk/bsd.pkg.mk"
