# $NetBSD: Makefile,v 1.3 2006/01/11 18:26:59 wiz Exp $

DISTNAME=	hyperestraier-1.1.2
CATEGORIES=	japanese textproc www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hyperestraier/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://hyperestraier.sourceforge.net/
COMMENT=	Full-text search system for communities

GNU_CONFIGURE=		yes
USE_TOOLS+=	pkg-config
PKGCONFIG_OVERRIDE=	hyperestraier.pc.in
TEST_TARGET=            check

.include "../../databases/qdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
