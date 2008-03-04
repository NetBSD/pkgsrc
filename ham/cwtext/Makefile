# $NetBSD: Makefile,v 1.16 2008/03/04 15:51:59 jlam Exp $

DISTNAME=	cwtext-0.95
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cwtext/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cwtext.sourceforge.net/
COMMENT=	Morse Code Generator

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FILE=	makefile
USE_TOOLS+=	gmake
BUILD_TARGET=	ALL

INSTALLATION_DIRS=	bin

post-patch:
	${SED} 	-e "s,^PREFIX,#PREFIX,g"	\
		-e "s,gcc,${CC} ${CFLAGS},g"	\
		-e "s,python,${PYTHONBIN},g"	\
		${WRKSRC}/${MAKE_FILE} > ${WRKSRC}/${MAKE_FILE}.done
	${MV} ${WRKSRC}/${MAKE_FILE}.done ${WRKSRC}/${MAKE_FILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cwpcm ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cwtext ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cwmm ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
