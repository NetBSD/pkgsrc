# $NetBSD: Makefile,v 1.7 2010/02/05 08:44:03 obache Exp $

DISTNAME=	gettext-0.14.6
PKGNAME=	gettext-asprintf-0.14.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gettext/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gettext/gettext.html
COMMENT=	Provides a printf-like interface for C++

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_DIRS=		gettext-runtime
BUILD_DIRS=		gettext-runtime/libasprintf

INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
