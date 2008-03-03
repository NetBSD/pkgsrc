# $NetBSD: Makefile,v 1.4 2008/03/03 00:51:44 jlam Exp $
#

DISTNAME=	forkbomb-1.4
CATEGORIES=	benchmarks
MASTER_SITES=	http://home.tiscali.cz:8080/~cz210552/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.tiscali.cz:8080/~cz210552/forkbomb.html
COMMENT=	Classic Unix fork() bomber

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	bin man/man8

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} ${WRKSRC}/forkbomb.c -o \
		${WRKSRC}/forkbomb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/forkbomb ${DESTDIR}${PREFIX}/bin
	1${INSTALL_MAN} ${WRKSRC}/forkbomb.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
