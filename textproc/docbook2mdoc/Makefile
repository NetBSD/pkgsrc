# $NetBSD: Makefile,v 1.4 2014/04/30 13:57:15 wiz Exp $

DISTNAME=	docbook2mdoc-0.0.9
CATEGORIES=	textproc
MASTER_SITES=	http://mdocml.bsd.lv/docbook2mdoc/snapshots/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mdocml.bsd.lv/docbook2mdoc/
COMMENT=	Convert DocBook documentation into man pages (mdoc)
LICENSE=	isc

BUILD_TARGET=	docbook2mdoc
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
