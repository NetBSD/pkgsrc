# $NetBSD: Makefile,v 1.39 2009/05/19 08:59:13 wiz Exp $

DISTNAME=	spim-7.3
CATEGORIES=	emulators
MASTER_SITES=	http://pages.cs.wisc.edu/~larus/SPIM/ 

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pages.cs.wisc.edu/~larus/spim.html
COMMENT=	MIPS R2000 Simulator
LICENSE=	spim-license

RESTRICTED=		No permission to copy, and prohibited commercially.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
HAS_CONFIGURE=		yes
CONFIGURE_DIRS=		xspim
BUILD_DIRS=		spim xspim
CONFIGURE_SCRIPT=	./Configure
USE_IMAKE=		yes
USE_TOOLS+=		gzip flex yacc
XMKMF=			${X11BASE}/bin/xmkmf # don't specify -a option
INSTALL_TARGET=		install

SUBST_CLASSES+=		cpudir
SUBST_STAGE.cpudir=	post-patch
SUBST_MESSAGE.cpudir=	rename CPU_DIR
SUBST_FILES.cpudir=	spim/Makefile xspim/Imakefile
SUBST_SED.cpudir=	-e s:CPU_DIR:CPUDIR:

INSTALLATION_DIRS=	bin share/spim share/doc/spim man/man1

post-configure:
	cd ${WRKSRC}/spim && ${SETENV} ${_CONFIGURE_SCRIPT_ENV}		\
                ${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS}			\
                        ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

post-install:
	@${ECHO} "Installing spim/xspim documentation"
	${INSTALL_DATA} ${WRKSRC}/Documentation/spim.man \
		${DESTDIR}${PREFIX}/man/man1/spim.1
	${INSTALL_DATA} ${WRKSRC}/Documentation/xspim.man \
		${DESTDIR}${PREFIX}/man/man1/xspim.1
	${INSTALL_DATA} ${WRKSRC}/Documentation/TeX/spim.tex \
		${DESTDIR}${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/TeX/*.id \
		${DESTDIR}${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/TeX/cycle.ps \
		${DESTDIR}${PREFIX}/share/doc/spim

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
