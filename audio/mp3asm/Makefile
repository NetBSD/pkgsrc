# $NetBSD: Makefile,v 1.4 2003/03/29 12:40:07 jmmv Exp $
#

DISTNAME=	mp3asm-0.1.3
WRKSRC=		${WRKDIR}/mp3asm-0.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3asm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://mp3asm.sourceforge.net/
COMMENT=	mpeg 1/2/2.5 audio layer 1,2,3 frame level editor

GNU_CONFIGURE=	yes

post-patch:
	${SED} "s/getprogname/_getprogname/g" ${WRKSRC}/src/mp3asm.c		\
		> ${WRKSRC}/src/mp3asm.c.done
	${MV} ${WRKSRC}/src/mp3asm.c.done ${WRKSRC}/src/mp3asm.c

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mp3asm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mp3asm

.include "../../mk/bsd.pkg.mk"
