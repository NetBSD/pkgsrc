# $NetBSD: Makefile,v 1.27 2005/12/01 19:33:10 wiz Exp $

DISTNAME=	nn-6.6.5
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.nndev.org/pub/nn-6.6/ \
		ftp://ftp.nndev.org/pub/nn-6.6/old/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	NN newsreader

PKG_SYSCONFSUBDIR=	nntp

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
.elif ${LOWER_ARCH} == "mipseb"
MFILE=         m-mipsel.h
.else
MFILE=		m-${LOWER_ARCH}.h
.endif

MAKE_ENV+=	CC=${CC:Q}

post-patch:
	@${SED} -e ' \
	    s#@PREFIX@#${PREFIX}#; \
	    s#@PKG_SYSCONFDIR@#${PKG_SYSCONFDIR}#; \
	    s#@BINOWN@#${BINOWN}#; \
	    s#@BINGRP@#${BINGRP}#; \
	    s#@MFILE@#${MFILE}#; \
	    s#@SFILE@#${SFILE}#' \
	    <${WRKSRC}/config.h-dist >${WRKSRC}/config.h
	@${CP} ${FILESDIR}/s-netbsd.h ${WRKSRC}/conf/s-netbsd.h
	@${CP} ${FILESDIR}/m-powerpc.h ${WRKSRC}/conf/m-powerpc.h
	@${CP} ${WRKSRC}/conf/m-m680x0.h ${WRKSRC}/conf/m-m68k.h

.include "../../mk/bsd.pkg.mk"
