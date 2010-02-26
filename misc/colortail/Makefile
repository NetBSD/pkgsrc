# $NetBSD: Makefile,v 1.18 2010/02/26 10:28:33 wiz Exp $

DISTNAME=	colortail-0.3.0
CATEGORIES=	misc
MASTER_SITES=	http://joakimandersson.se/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://joakimandersson.se/projects/colortail/
COMMENT=	Colour-able replacement for tail(1)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--datadir=${PREFIX}/share/examples/colortail

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/examples/colortail

post-install:
	${INSTALL_MAN} ${WRKSRC}/colortail.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC}/example-conf/ && \
	${INSTALL_DATA} conf.kernel conf.messages conf.secure \
		conf.xferlog conf.daemon ${DESTDIR}${PREFIX}/share/examples/colortail

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
