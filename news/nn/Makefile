# $NetBSD: Makefile,v 1.17 2002/07/08 02:21:18 kim Exp $
# FreeBSD Id: Makefile,v 1.14 1997/07/30 18:17:48 adam Exp
#

DISTNAME=	nn-6.6.4
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.gw.com/pub/unix/news/nn/nn-6.6/ \
		ftp://ftp.gw.com/pub/unix/news/nn/nn-6.6/old/ \
		ftp://ftp.nndev.org/pub/nn-6.6/ \
		ftp://ftp.nndev.org/pub/nn-6.6/old/

MAINTAINER=	packages@netbsd.org
COMMENT=	NN newsreader

BUILD_DEFS+=	USE_INN

.include "../../mk/bsd.prefs.mk"

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
	@${CP} ${FILESDIR}/m-powerpc.h ${WRKSRC}/conf/m-powerpc.h
	@${CP} ${WRKSRC}/conf/m-m680x0.h ${WRKSRC}/conf/m-m68k.h

.include "../../mk/bsd.pkg.mk"
