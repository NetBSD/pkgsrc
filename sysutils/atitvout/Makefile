# $NetBSD: Makefile,v 1.15 2016/07/10 10:45:40 rillig Exp $

DISTNAME=	atitvout-0.4
PKGREVISION=	1
CATEGORIES=	sysutils graphics
MASTER_SITES=	http://0pointer.de/lennart/projects/atitvout/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/atitvout/
COMMENT=	Allows TV-Out connector support under Linux/NetBSD

ONLY_FOR_PLATFORM=	NetBSD-*-i386 # Linux-*-i386 [gnumakefile needs work]

WRKSRC=			${WRKDIR}/atitvout
HAS_CONFIGURE=		yes

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

INSTALLATION_DIRS=	sbin share/doc/atitvout

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/atitvout ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/atitvout
	${INSTALL_DATA} ${WRKSRC}/test.sh ${DESTDIR}${PREFIX}/share/doc/atitvout

.include "../../mk/bsd.pkg.mk"
