# $NetBSD: Makefile,v 1.7 2001/10/31 08:10:54 zuntum Exp $
# FreeBSD Id: Makefile,v 1.3 1997/08/15 16:47:08 jmz Exp
#

DISTNAME=	lile-2.0
PKGNAME=	ile-2.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.inria.fr/system/user/
EXTRACT_SUFX=	.tar.z

MAINTAINER=	packages@netbsd.org
COMMENT=	Input Line Editor that wraps itself around programs

post-patch:
	@(cd ${WRKSRC}; ${SED} "s,/usr/local,${PREFIX}," Makefile	\
		> Makefile.done; ${MV} Makefile.done Makefile;		\
		${ECHO} all: ile >> Makefile;				\
		${ECHO} CC=${CC} ${CFLAGS} >> Makefile )

.include "../../mk/bsd.pkg.mk"
