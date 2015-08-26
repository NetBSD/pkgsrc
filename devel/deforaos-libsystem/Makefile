# $NetBSD: Makefile,v 1.13 2015/08/26 22:34:03 khorben Exp $
#

DISTNAME=	libSystem-0.2.2
PKGNAME=	deforaos-libsystem-0.2.2
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/4359/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS core system library

LICENSE=	gnu-lgpl-v3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	INSTALL=${INSTALL}
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/configctl.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/configctl.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/configctl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/configctl.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

REPLACE_SH=	tests/tests.sh

BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.20
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
