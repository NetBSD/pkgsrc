# $NetBSD: Makefile,v 1.5 2008/02/02 17:05:00 rillig Exp $
#

DISTNAME=	veleng10
PKGNAME=	velena-1.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.ce.unipr.it/~gbe/
EXTRACT_SUFX=	.zip

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.ce.unipr.it/~gbe/
COMMENT=	Perfect-play engine for connect four

LICENSE=		public-domain
RESTRICTED=		You must not charge a fee for this software nor for any derived work in which this software is included.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

EXTRACT_OPTS_ZIP=	-LLaqo
WRKSRC=			${WRKDIR}
MAKE_FILE=		makefile
INSTALLATION_DIRS_FROM_PLIST=	yes

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	connect4.h
SUBST_SED.path=		-e 's,"white_ob.cn4","${PREFIX}/share/velena/white_ob.cn4",'

SUBST_CLASSES+=		ansi-c
SUBST_STAGE.ansi-c=	pre-configure
SUBST_FILES.ansi-c=	*.c *.h
SUBST_SED.ansi-c=	-e 's,<malloc\.h>,<stdlib.h>,'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/veleng ${DESTDIR}${PREFIX}/bin/velena
	${INSTALL_DATA} ${WRKSRC}/readme ${DESTDIR}${PREFIX}/share/doc/velena/README
	${INSTALL_DATA} ${WRKSRC}/white_ob.cn4 ${DESTDIR}${PREFIX}/share/velena/.

.include "../../mk/bsd.pkg.mk"
