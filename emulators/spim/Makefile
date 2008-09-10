# $NetBSD: Makefile,v 1.35 2008/09/10 00:32:08 gdt Exp $

DISTNAME=	spim-7.1
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://pages.cs.wisc.edu/~larus/SPIM/ \
		ftp://ftp.cs.wisc.edu/pub/spim/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pages.cs.wisc.edu/~larus/spim.html
COMMENT=	MIPS R2000 Simulator

LICENSE=		spim-license
RESTRICTED=		No permission to copy, and prohibited commercially.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

#DIST_SUBDIR=		${PKGNAME}

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
USE_IMAKE=		yes
USE_TOOLS+=		gzip lex yacc
XMKMF=			${X11BASE}/bin/xmkmf # don't specify -a option

BUILD_TARGET=		y.tab.c depend all

pre-configure:
	@${RM} -f ${WRKSRC}/y.tab.*

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/spim
	${CHMOD} a+rx ${PREFIX}/share/spim

post-install:
	@${ECHO} "Installing spim/xspim documentation"
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/spim \
		&& ${CHMOD} a+rx ${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/spim.tex \
		${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/*.id \
		${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/cycle.ps \
		${PREFIX}/share/doc/spim

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
