# $NetBSD: Makefile,v 1.15 2020/03/20 11:57:22 nia Exp $
#

DISTNAME=	mp3asm-0.1.3-1
PKGNAME=	mp3asm-0.1.3.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3asm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://mp3asm.sourceforge.net/
COMMENT=	MPEG 1/2/2.5 audio layer 1,2,3 frame level editor
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/mp3asm-0.1
GNU_CONFIGURE=	yes

INSTALLATION_DIRS+=	share/doc/mp3asm

post-patch:
	${SED} "s/getprogname/_getprogname/g" ${WRKSRC}/src/mp3asm.c		\
		> ${WRKSRC}/src/mp3asm.c.done
	${MV} ${WRKSRC}/src/mp3asm.c.done ${WRKSRC}/src/mp3asm.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mp3asm

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
