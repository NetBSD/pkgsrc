# $NetBSD: Makefile,v 1.8 2003/06/02 01:18:12 jschauma Exp $
# FreeBSD Id: Makefile,v 1.3 1997/08/15 16:47:08 jmz Exp
#

DISTNAME=	lile-2.0
PKGNAME=	ile-2.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.inria.fr/system/user/
EXTRACT_SUFX=	.tar.z

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Input Line Editor that wraps itself around programs

post-patch:
	@(cd ${WRKSRC}; ${SED} "s,/usr/local,${PREFIX}," Makefile	\
		> Makefile.done; ${MV} Makefile.done Makefile;		\
		${ECHO} all: ile >> Makefile;				\
		${ECHO} CC=${CC} ${CFLAGS} >> Makefile )

.include "../../mk/bsd.pkg.mk"
