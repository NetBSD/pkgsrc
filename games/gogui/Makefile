# $NetBSD: Makefile,v 1.2 2006/09/20 14:24:44 rillig Exp $
#

DISTNAME=		gogui-0.9
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gogui/}
EXTRACT_SUFX=		.zip

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://gogui.sourceforge.net/
COMMENT=		GUI for Go-playing programs

REPLACE_BASH+=		bin/*
USE_TOOLS+=		bash:run

SUBST_CLASSES+=		gogui
SUBST_STAGE.gogui=	do-configure
SUBST_MESSAGE.gogui=	Fixing hard-coded paths.
SUBST_FILES.gogui=	bin/*
SUBST_SED.gogui=	-e 's;^\(GOGUI_LIB\)=.*;\1="${LIBDIR}";'

USE_JAVA2=		yes
USE_TOOLS+=		printf

LIBDIR=			${PREFIX}/share/gogui/lib
DOCDIR=			${PREFIX}/share/doc/gogui
MY_MANDIR=		${PREFIX}/${PKGMANDIR}
INSTALLATION_DIRS=	bin ${LIBDIR} ${DOCDIR} ${MY_MANDIR}

do-build:
.for p in gmptogtp gogui gtpadapter gtpdisplay gtpdummy gtpregress	\
	gtpserver gtpstatistics gtpterminal netgtp sgfthumbnail		\
	sgftotex twogtp
	printf "#! /bin/sh\\nexec \"${PKG_JAVA_HOME}/bin/java\" -jar \"${PREFIX}/share/gogui/lib/${p}.jar\" \"\$$@\"\\n" > ${WRKSRC}/bin/${p}
.endfor

do-install:
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} * ${PREFIX}/bin/.
	cd ${WRKSRC}/lib && ${INSTALL_DATA} *.jar ${LIBDIR}/.
	cd ${WRKSRC}/doc/manual/html && ${INSTALL_DATA} *.html *.png ${DOCDIR}/.
	cd ${WRKSRC}/doc/manual/man && ${INSTALL_MAN} *.1 ${MY_MANDIR}/man1/.

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
