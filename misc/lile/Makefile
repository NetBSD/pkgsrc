# $NetBSD: Makefile,v 1.4 1998/04/20 11:56:28 frueauf Exp $
# FreeBSD Id: Makefile,v 1.3 1997/08/15 16:47:08 jmz Exp
#

DISTNAME=	lile-2.0
PKGNAME=	ile-2.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.inria.fr/system/user/
EXTRACT_SUFX=	.tar.z

MAINTAINER=	packages@netbsd.org

MAN1=		ile.1

do-configure:
	@(cd ${WRKSRC}; ${MV} Makefile Makefile.old; \
	${SED} -e s:/usr/local:${PREFIX}: <Makefile.old > Makefile; \
	${ECHO} all: ile >> Makefile; ${ECHO} CC=cc ${CFLAGS} >> Makefile)

.include "../../mk/bsd.pkg.mk"
