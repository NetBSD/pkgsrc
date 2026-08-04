# $NetBSD: Makefile,v 1.49 2026/08/04 20:28:54 wiz Exp $

DISTNAME=	spim-8.0
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	https://pages.cs.wisc.edu/~larus/SPIM/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://spimsimulator.sourceforge.net/
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
SUBST_STAGE.cpudir=	pre-configure
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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
