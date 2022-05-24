# $NetBSD: Makefile,v 1.28 2022/05/24 13:02:34 nia Exp $

DISTNAME=	mousetar-20021217
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.rodents-montreal.org/pub/mouse/ftp.netbsd.org/tar/
DISTFILES=	tar.c tar.man

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	none
COMMENT=	Version of tar program from der Mouse

NOT_FOR_PLATFORM+=	Interix-*-* # no sys/mtio.h tape support

WRKSRC=		${WRKDIR}

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-DDIRENT_FIXUP
CPPFLAGS.SunOS+=	-DTAR_INODE_NONE -DLINUX_NAMLEN
CPPFLAGS.SunOS+=	-DL_SET=SEEK_SET -DL_INCR=SEEK_CUR -DL_XTND=SEEK_END
CPPFLAGS.Linux+=	-DLINUX_NAMLEN

CPPFLAGS.NetBSD+=	-DTAR_INODE_INTERNAL

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-extract:
	for f in ${DISTFILES}; do					\
		${CP} ${DISTDIR}/$$f ${WRKDIR};				\
	done

do-build:
	cd ${WRKSRC}; ${CC} ${CPPFLAGS} ${CFLAGS} tar.c -o mousetar

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mousetar ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tar.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mousetar.1

.include "../../mk/bsd.pkg.mk"
