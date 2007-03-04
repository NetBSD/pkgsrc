# $NetBSD: Makefile,v 1.14 2007/03/04 11:30:33 wiz Exp $

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

post-patch:
	@(cd ${WRKSRC}; ${SED} "s,/usr/local,${PREFIX}," Makefile	\
		> Makefile.done; ${MV} Makefile.done Makefile;		\
		${ECHO} all: ile >> Makefile;				\
		${ECHO} CC=${CC} ${CFLAGS} >> Makefile )

.include "../../mk/bsd.pkg.mk"
