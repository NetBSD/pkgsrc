# $NetBSD: Makefile,v 1.6 2006/04/02 20:18:37 wiz Exp $

DISTNAME=	hyperestraier-1.1.6
CATEGORIES=	japanese textproc www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hyperestraier/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://hyperestraier.sourceforge.net/
COMMENT=	Full-text search system for communities

GNU_CONFIGURE=		yes
USE_TOOLS+=	pkg-config
PKGCONFIG_OVERRIDE=	hyperestraier.pc.in
TEST_TARGET=            check

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/qdbm/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
