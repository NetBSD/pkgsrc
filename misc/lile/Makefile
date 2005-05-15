# $NetBSD: Makefile,v 1.11 2005/05/15 19:21:46 jlam Exp $

DISTNAME=	lile-2.0
PKGNAME=	ile-2.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.inria.fr/system/user/
EXTRACT_SUFX=	.tar.z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Input Line Editor that wraps itself around programs

PKGSRC_USE_TOOLS+=	gzcat

post-patch:
	@(cd ${WRKSRC}; ${SED} "s,/usr/local,${PREFIX}," Makefile	\
		> Makefile.done; ${MV} Makefile.done Makefile;		\
		${ECHO} all: ile >> Makefile;				\
		${ECHO} CC=${CC} ${CFLAGS} >> Makefile )

.include "../../mk/bsd.pkg.mk"
