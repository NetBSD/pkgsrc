# $NetBSD: Makefile,v 1.13 2000/02/27 23:37:53 tron Exp $
# FreeBSD Id: Makefile,v 1.14 1997/07/30 18:17:48 adam Exp
#

DISTNAME=	nn-6.5.4
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.gw.com/pub/unix/news/nn/

MAINTAINER=     packages@netbsd.org

BUILD_DEFS+=	USE_INN

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INN) && ${USE_INN} == YES
DEPENDS=	inn>=2.2:../inn
.else
DEPENDS=	nntpclnt-1.6.1:../nntpclnt
.endif

.if ${OPSYS} == "SunOS"
SFILE=		s-sunos5.h
.elif ${OPSYS} == "Linux"
SFILE=		s-linux.h
.else
SFILE=		s-netbsd.h
.endif

.if ${LOWER_ARCH} == "i386"
MFILE=		m-i80386.h
.else
MFILE=		m-${LOWER_ARCH}.h
.endif

MAKE_ENV+=	CC="${CC}"

post-patch:
	@${SED} -e ' \
	    s#@PREFIX@#${PREFIX}#; \
	    s#@BINOWN@#${BINOWN}#; \
	    s#@BINGRP@#${BINGRP}#; \
	    s#@MFILE@#${MFILE}#; \
	    s#@SFILE@#${SFILE}#' \
	    <${WRKSRC}/config.h-dist >${WRKSRC}/config.h
	@${CP} ${FILESDIR}/s-netbsd.h ${WRKSRC}/conf/s-netbsd.h

.include "../../mk/bsd.pkg.mk"
