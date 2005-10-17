# $NetBSD: Makefile,v 1.9 2005/10/17 16:01:39 reed Exp $

DISTNAME=	colortail-0.3.0
CATEGORIES=	misc
MASTER_SITES=	http://morrdusk.net/files/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://morrdusk.net/projects/colortail/
COMMENT=	Colour-able replacement for tail(1)

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--datadir=${PREFIX}/share/examples/colortail
DESCR_SRC=	${WRKDIR}/.DESCR_SRC

post-install:
	${INSTALL_MAN} ${WRKSRC}/colortail.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/colortail
	cd ${WRKSRC}/example-conf/ && \
	${INSTALL_DATA} conf.kernel conf.messages conf.secure \
		conf.xferlog conf.daemon ${PREFIX}/share/examples/colortail
	${SED} 's,@PREFIX@,${PREFIX},' ${PKGDIR}/DESCR > ${DESCR_SRC}

.include "../../mk/bsd.pkg.mk"
