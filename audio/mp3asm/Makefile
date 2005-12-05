# $NetBSD: Makefile,v 1.9 2005/12/05 20:49:49 rillig Exp $
#

DISTNAME=	mp3asm-0.1.3-1
PKGNAME=	mp3asm-0.1.3.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3asm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://mp3asm.sourceforge.net/
COMMENT=	MPEG 1/2/2.5 audio layer 1,2,3 frame level editor

WRKSRC=		${WRKDIR}/mp3asm-0.1
GNU_CONFIGURE=	yes

post-patch:
	${SED} "s/getprogname/_getprogname/g" ${WRKSRC}/src/mp3asm.c		\
		> ${WRKSRC}/src/mp3asm.c.done
	${MV} ${WRKSRC}/src/mp3asm.c.done ${WRKSRC}/src/mp3asm.c

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mp3asm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mp3asm

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
