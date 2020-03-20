# $NetBSD: Makefile,v 1.10 2020/03/20 11:57:41 nia Exp $
#

DISTNAME=		gogui-0.9.3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gogui/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
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
INSTALLATION_DIRS=	bin ${LIBDIR} ${DOCDIR} ${PKGMANDIR}/man1

do-build:
.for p in gmptogtp gogui gtpadapter gtpdisplay gtpdummy gtpregress	\
	gtpserver gtpstatistics gtpterminal netgtp sgfthumbnail		\
	sgftotex twogtp
	printf "#! /bin/sh\\nexec \"${PKG_JAVA_HOME}/bin/java\" -jar \"${PREFIX}/share/gogui/lib/${p}.jar\" \"\$$@\"\\n" > ${WRKSRC}/bin/${p}
.endfor

do-install:
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} * ${DESTDIR}${PREFIX}/bin/.
	cd ${WRKSRC}/lib && ${INSTALL_DATA} *.jar ${DESTDIR}${LIBDIR}/.
	cd ${WRKSRC}/doc/manual/html && ${INSTALL_DATA} *.html *.png \
		${DESTDIR}${DOCDIR}/.
	cd ${WRKSRC}/doc/manual/man && ${INSTALL_MAN} *.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
