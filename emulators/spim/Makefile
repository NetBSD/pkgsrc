# $NetBSD: Makefile,v 1.3 1998/08/20 15:16:53 tsarna Exp $
# FreeBSD Id: Makefile,v 1.5 1997/10/10 06:53:35 obrien Exp
#

DISTNAME=		spim
PKGNAME=		spim-6.1
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.cs.wisc.edu/pub/spim/

MAINTAINER=		deberg@mit.edu
HOMEPAGE=		http://www.cs.wisc.edu/~larus/spim.html

NO_WRKSUBDIR=		yes

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
USE_IMAKE=		yes
XMKMF=			xmkmf # don't specify -a option

ALL_TARGET=		y.tab.c depend spim xspim

pre-configure:
	@${RM} -f ${WRKSRC}/y.tab.*

pre-install:
	@${MKDIR} ${PREFIX}/share/spim && chmod a+rx ${PREFIX}/share/spim

post-install:
	@${ECHO} "Installing spim/xspim documentation"
	@${MKDIR} ${PREFIX}/share/doc/spim  \
		&& chmod a+rx ${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/spim.ps  \
		${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/cycle.ps  \
		${PREFIX}/share/doc/spim
	${GZIP_CMD} ${PREFIX}/share/doc/spim/*.ps

.include "../../mk/bsd.pkg.mk"
