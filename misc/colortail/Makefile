# $NetBSD: Makefile,v 1.1.1.1 2001/01/24 03:53:06 hubertf Exp $
# FreeBSD Id: ports/misc/colortail/Makefile,v 1.10 2000/06/28 17:20:27 alex Exp

DISTNAME=	colortail-0.3.0
CATEGORIES=	misc
MASTER_SITES=	http://www.student.hk-r.se/~pt98jan/

MAINTAINER=	zuntum@eik.pl
HOMEPAGE=	http://www.student.hk-r.se/~pt98jan/colortail.html

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--datadir=${PREFIX}/share/examples/colortail
DESCR_SRC=	${WRKDIR}/.DESCR_SRC

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/colortail
	cd ${WRKSRC}/example-conf/ && \
	${INSTALL_DATA} conf.kernel conf.messages conf.secure \
		conf.xferlog conf.daemon ${PREFIX}/share/examples/colortail
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|' \
		<${PKGDIR}/DESCR >${DESCR_SRC}

.include "../../mk/bsd.pkg.mk"
