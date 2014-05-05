# $NetBSD: Makefile,v 1.3 2014/05/05 21:11:25 ryoon Exp $

DISTNAME=	libexecinfo-1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_FREEBSD}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ober@NetBSD.org
HOMEPAGE=       http://www.freebsdsoftware.org/devel/libexecinfo.html
COMMENT=	BSD Licensed clone of backtrace facility found in GNU libc
LICENSE=	2-clause-bsd

USE_BSD_MAKEFILE=	yes
MAKE_FLAGS+=	MKLINT=no

CFLAGS.Linux+=	-D_GNU_SOURCE # Dl_info internals
CFLAGS.Linux+=	-Wno-unused-result # write(2) is declared specially

INSTALLATION_DIRS=	include lib

.include "../../mk/bsd.prefs.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/execinfo.h ${DESTDIR}${PREFIX}/include
# OpenBSD's /usr/share/mk/bsd.lib.mk does not create the following symlinks.
.if ${OPSYS} == "OpenBSD"
	cd ${DESTDIR}${PREFIX}/lib && \
		${LN} -sf libexecinfo.so.1.0 libexecinfo.so
	cd ${DESTDIR}${PREFIX}/lib && \
		${LN} -sf libexecinfo.so.1.0 libexecinfo.so.1
.endif

.include "../../mk/bsd.pkg.mk"
