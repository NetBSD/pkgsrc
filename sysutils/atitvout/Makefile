# $NetBSD: Makefile,v 1.12 2008/01/05 04:56:27 obache Exp $

DISTNAME=	atitvout-0.4
PKGREVISION=	1
CATEGORIES=	sysutils graphics
MASTER_SITES=	http://0pointer.de/lennart/projects/atitvout/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/atitvout/
COMMENT=	Allows TV-Out connector support under Linux/NetBSD

ONLY_FOR_PLATFORM=	NetBSD-*-i386 # Linux-*-i386 [gnumakefile needs work]

WRKSRC=			${WRKDIR}/atitvout
USE_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.include "../../emulators/lrmi/buildlink3.mk"

MAKE_FILE=	Makefile.bsd

do-configure:
	${CP} ${FILESDIR}/Makefile.bsd ${WRKSRC}
.endif

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	test.sh

SUBST_CLASSES+=	sh
SUBST_STAGE.sh=	pre-configure
SUBST_FILES.sh=	test.sh
SUBST_SED.sh=	-e "s,@PREFIX@,${PREFIX},"

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/atitvout ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/atitvout
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/atitvout
	${INSTALL_DATA} ${WRKSRC}/test.sh ${PREFIX}/share/doc/atitvout

.include "../../mk/bsd.pkg.mk"
