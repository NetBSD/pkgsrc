# $NetBSD: Makefile,v 1.1.1.1 2006/07/27 14:52:26 rillig Exp $
#

DISTNAME=		gogui-0.9
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

NO_BUILD=		yes

LIBDIR=			${PREFIX}/share/gogui/lib
DOCDIR=			${PREFIX}/share/doc/gogui
MY_MANDIR=		${PREFIX}/${PKGMANDIR}
INSTALLATION_DIRS=	bin ${LIBDIR} ${DOCDIR} ${MY_MANDIR}

do-install:
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} * ${PREFIX}/bin/.
	cd ${WRKSRC}/lib && ${INSTALL_DATA} *.jar ${LIBDIR}/.
	cd ${WRKSRC}/doc/manual/html && ${INSTALL_DATA} *.html *.png ${DOCDIR}/.
	cd ${WRKSRC}/doc/manual/man && ${INSTALL_MAN} *.1 ${MY_MANDIR}/man1/.

.include "../../mk/bsd.pkg.mk"
