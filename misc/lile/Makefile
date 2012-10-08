# $NetBSD: Makefile,v 1.16 2012/10/08 09:57:29 asau Exp $

DISTNAME=	lile-2.0
PKGNAME=	ile-2.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.inria.fr/system/user/
EXTRACT_SUFX=	.tar.z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Input Line Editor that wraps itself around programs

# uses struct sgttyb
NOT_FOR_PLATFORM=	Linux-*-*

USE_TOOLS+=	gzcat

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

post-patch:
	@(cd ${WRKSRC}; ${SED} "s,/usr/local,${PREFIX}," Makefile	\
		> Makefile.done; ${MV} Makefile.done Makefile;		\
		${ECHO} all: ile >> Makefile;				\
		${ECHO} CC=${CC} ${CFLAGS} >> Makefile )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ile ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ile.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
