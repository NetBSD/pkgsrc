# $NetBSD: Makefile,v 1.1 2014/03/31 08:13:32 wiz Exp $

DISTNAME=	docbook2mdoc-0.0.5
CATEGORIES=	textproc
MASTER_SITES=	http://mdocml.bsd.lv/docbook2mdoc/snapshots/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mdocml.bsd.lv/docbook2mdoc/
COMMENT=	Convert DocBook documentation into man pages (mdoc)
LICENSE=	isc

BUILD_TARGET=	docbook2mdoc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/docbook2mdoc ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docbook2mdoc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
