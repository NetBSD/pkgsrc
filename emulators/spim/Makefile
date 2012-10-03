# $NetBSD: Makefile,v 1.43 2012/10/03 12:55:18 asau Exp $

DISTNAME=	spim-8.0
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://pages.cs.wisc.edu/~larus/SPIM/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spimsimulator.sourceforge.net/
COMMENT=	MIPS R2000 Simulator
LICENSE=	modified-bsd

HAS_CONFIGURE=		yes
CONFIGURE_DIRS=		xspim
BUILD_DIRS=		spim xspim
CONFIGURE_SCRIPT=	./Configure
USE_IMAKE=		yes
USE_TOOLS+=		gzip flex yacc
INSTALL_TARGET=		install

SUBST_CLASSES+=		cpudir
SUBST_STAGE.cpudir=	post-patch
SUBST_MESSAGE.cpudir=	rename CPU_DIR
SUBST_FILES.cpudir=	spim/Makefile xspim/Imakefile
SUBST_SED.cpudir=	-e s:CPU_DIR:CPUDIR:

INSTALLATION_DIRS=	share/doc/${PKGBASE} ${PKGMANDIR}/man1

post-configure:
	cd ${WRKSRC}/spim && ${SETENV} ${_CONFIGURE_SCRIPT_ENV}		\
                ${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS}			\
                        ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

post-install:
	@${ECHO} "Installing spim/xspim documentation"
	${INSTALL_DATA} ${WRKSRC}/Documentation/spim.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/spim.1
	${INSTALL_DATA} ${WRKSRC}/Documentation/xspim.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xspim.1
	${INSTALL_DATA} ${WRKSRC}/Documentation/TeX/spim.tex \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/Documentation/TeX/*.id \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/Documentation/TeX/cycle.ps \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
