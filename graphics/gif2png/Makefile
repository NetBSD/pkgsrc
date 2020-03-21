# $NetBSD: Makefile,v 1.61 2020/03/21 16:57:17 bsiegert Exp $

DISTNAME=	gif2png-3.0.0
PKGREVISION=	4
CATEGORIES=	graphics
#MASTER_SITES=	https://gitlab.com/esr/gif2png/-/archive/master/
MASTER_SITES=	http://www.catb.org/~esr/gif2png/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/esr/gif2png/
COMMENT=	Convert GIFs to PNG format
LICENSE=	modified-bsd

GO_SRCPATH=	gitlab.com/esr/gif2png
GO_DIST_BASE=	${DISTNAME}

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

REPLACE_PYTHON+=	${WRKSRC}/web2png

post-build:
	cd ${WRKSRC} && \
		xmlto man gif2png.xml && \
		xmlto man web2png.xml

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/web2png ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/gif2png.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/web2png.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../security/go-crypto/buildlink3.mk"
.include "../../devel/go-sys/buildlink3.mk"

.include "../../lang/go/go-package.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
