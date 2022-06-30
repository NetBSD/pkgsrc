# $NetBSD: Makefile,v 1.88 2022/06/30 11:18:27 nia Exp $

DISTNAME=	gif2png-3.0.0
PKGREVISION=	30
CATEGORIES=	graphics
#MASTER_SITES=	https://gitlab.com/esr/gif2png/-/archive/master/
MASTER_SITES=	http://www.catb.org/~esr/gif2png/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/esr/gif2png/
COMMENT=	Convert GIFs to PNG format
LICENSE=	modified-bsd

GO_BUILD_PATTERN=	.

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

REPLACE_PYTHON+=	${WRKSRC}/web2png

pre-patch:
	cp ${FILESDIR}/go.mod ${FILESDIR}/go.sum ${WRKSRC}

post-build:
	cd ${WRKSRC} && \
		xmlto man gif2png.xml && \
		xmlto man web2png.xml

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/web2png ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/gif2png.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/web2png.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
