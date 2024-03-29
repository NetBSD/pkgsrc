# $NetBSD: Makefile,v 1.54 2023/08/18 05:19:23 mlelstv Exp $

DISTNAME=	nn-6.7.3
PKGREVISION=	5
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.nndev.org/pub/nn-6.7/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nndev.org/
COMMENT=	NN newsreader

PKG_SYSCONFSUBDIR=	nntp

TOOL_DEPENDS+=	tradcpp-[0-9]*:../../devel/tradcpp

CPPFLAGS.IRIX+=	-DHAVE_TERMIO_H

# decode.c: In function 'decode_line':
# decode.c:132:22: error: array subscript has type 'char' [-Werror=char-subscripts]
#      if ((blen = trtbl[buf[0]]) < 0) {
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

OPSYSVARS+=	SFILE
SFILE.SunOS=	s-sunos5.h
SFILE.Linux=	s-linux.h
SFILE.*=	s-netbsd.h

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
MFILE=	m-i80386.h
.elif ${MACHINE_ARCH} == "mipseb"
MFILE=	m-mipsel.h
.elif ${MACHINE_CPU} == "aarch64" || ${MACHINE_CPU} == "arm"
MFILE=	m-arm.h
.else
MFILE=	m-${MACHINE_ARCH}.h
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

post-patch:
	@${SED} -e ' \
	    s#@PREFIX@#${PREFIX}#; \
	    s#@PKG_SYSCONFDIR@#${PKG_SYSCONFDIR}#; \
	    s#@PKGMANDIR@#${PKGMANDIR}#; \
	    s#@BINOWN@#${BINOWN}#; \
	    s#@BINGRP@#${BINGRP}#; \
	    s#@MFILE@#${MFILE}#; \
	    s#@SFILE@#${SFILE}#' \
	    <${WRKSRC}/config.h-dist >${WRKSRC}/config.h
	@${CP} ${FILESDIR}/s-netbsd.h ${WRKSRC}/conf/s-netbsd.h
	@${CP} ${FILESDIR}/m-powerpc.h ${WRKSRC}/conf/m-powerpc.h
	@${CP} ${FILESDIR}/m-x86_64.h ${WRKSRC}/conf/m-x86_64.h
	@${CP} ${WRKSRC}/conf/m-m680x0.h ${WRKSRC}/conf/m-m68k.h

SUBST_CLASSES+=		fix-dest
SUBST_STAGE.fix-dest=	post-build
SUBST_SED.fix-dest=	-e 's,${PREFIX},${DESTDIR}${PREFIX},'
SUBST_FILES.fix-dest=	inst


.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
