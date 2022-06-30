# $NetBSD: Makefile,v 1.30 2022/06/30 11:18:29 nia Exp $

DISTNAME=	cwtext-0.96
PKGREVISION=	7
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cwtext/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cwtext.sourceforge.net/
COMMENT=	Morse Code Generator

MAKE_FILE=	makefile
USE_TOOLS+=	gmake
BUILD_TARGET=	ALL

# harmless; the only call is properly guarded
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

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
	${INSTALL_DATA}    ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
