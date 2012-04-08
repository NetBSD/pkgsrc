# $NetBSD: Makefile,v 1.38.2.1 2012/04/08 09:19:15 sbd Exp $

DISTNAME=	nn-6.7.3
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.nndev.org/pub/nn-6.7/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nndev.org/
COMMENT=	NN newsreader

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_SYSCONFSUBDIR=	nntp

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if ${OPSYS} == "SunOS"
SFILE=		s-sunos5.h
.elif ${OPSYS} == "Linux"
SFILE=		s-linux.h
.else
SFILE=		s-netbsd.h
.endif

.if ${MACHINE_ARCH} == "i386"
MFILE=		m-i80386.h
.elif ${MACHINE_ARCH} == "mipseb"
MFILE=         m-mipsel.h
.else
MFILE=		m-${LOWER_ARCH}.h
.endif

.if ${OPSYS} == "DragonFly" || !empty(CC_VERSION:Mgcc*)
CPP+=		-traditional
.endif

.if ${OPSYS} == "IRIX"
CPPFLAGS+=	-DHAVE_TERMIO_H
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


.include "../../mk/bsd.pkg.mk"
