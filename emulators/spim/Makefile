# $NetBSD: Makefile,v 1.10 2001/09/09 20:36:22 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1997/10/10 06:53:35 obrien Exp
#

DISTNAME=		spim
PKGNAME=		spim-6.2
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.cs.wisc.edu/pub/spim/

MAINTAINER=		deberg@netbsd.org
HOMEPAGE=		http://www.cs.wisc.edu/~larus/spim.html
COMMENT=		MIPS R2000 Simulator

WRKSRC=			${WRKDIR}

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
USE_IMAKE=		yes
XMKMF=			${X11BASE}/bin/xmkmf # don't specify -a option

ALL_TARGET=		y.tab.c depend spim xspim

pre-configure:
	@${RM} -f ${WRKSRC}/y.tab.*

pre-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/spim && ${CHMOD} a+rx ${PREFIX}/share/spim

post-install:
	@${ECHO} "Installing spim/xspim documentation"
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/spim  \
		&& ${CHMOD} a+rx ${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/spim.ps  \
		${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/cycle.ps  \
		${PREFIX}/share/doc/spim
	${GZIP_CMD} ${PREFIX}/share/doc/spim/*.ps

.include "../../mk/bsd.pkg.mk"
