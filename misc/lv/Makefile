# $NetBSD: Makefile,v 1.23 2024/08/09 03:34:12 ryoon Exp $

DISTNAME=	lv451
PKGNAME=	lv-4.51
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	#

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
#HOMEPAGE=	http://www.ff.iij4u.or.jp/~nrt/lv/
HOMEPAGE=	https://github.com/ttdoda/lv/
COMMENT=	Powerful Multilingual File Viewer
LICENSE=	gnu-gpl-v2

CONFIGURE_DIRS=		build
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../src/configure

MAKE_ENV+=		LN=${LN:Q}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 lib/lv

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
