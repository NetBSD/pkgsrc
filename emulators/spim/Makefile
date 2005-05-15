# $NetBSD: Makefile,v 1.22 2005/05/15 22:02:26 jlam Exp $

DISTNAME=		spim
PKGNAME=		spim-6.5
CATEGORIES=		emulators
MASTER_SITES=		http://www.cs.wisc.edu/~larus/SPIM/ \
			ftp://ftp.cs.wisc.edu/pub/spim/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cs.wisc.edu/~larus/spim.html
COMMENT=		MIPS R2000 Simulator

DIST_SUBDIR=		${PKGNAME}

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
USE_IMAKE=		yes
USE_GNU_TOOLS+=		lex
XMKMF=			${X11BASE}/bin/xmkmf # don't specify -a option
PKGSRC_USE_TOOLS+=	gzip

BUILD_TARGET=		y.tab.c depend spim xspim

pre-configure:
	@${RM} -f ${WRKSRC}/y.tab.*

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/spim
	${CHMOD} a+rx ${PREFIX}/share/spim

post-install:
	@${ECHO} "Installing spim/xspim documentation"
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/spim \
		&& ${CHMOD} a+rx ${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/spim.ps \
		${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/cycle.ps \
		${PREFIX}/share/doc/spim
	${GZIP_CMD} ${PREFIX}/share/doc/spim/*.ps

.include "../../mk/bsd.pkg.mk"
