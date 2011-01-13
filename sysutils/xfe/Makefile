# $NetBSD: Makefile,v 1.35 2011/01/13 13:39:27 wiz Exp $

DISTNAME=	xfe-1.04
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xfe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://roland65.free.fr/xfe/
COMMENT=	Fast MS-Explorer like filemanager for X

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes

PTHREAD_AUTO_VARS=	yes

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	src/XFileExplorer.cc
SUBST_SED.conf=		-e "s|/usr/local|${PREFIX}|"
SUBST_MESSAGE.conf=	Fixing hardcoded path.

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/fox/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
