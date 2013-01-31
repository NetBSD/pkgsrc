# $NetBSD: Makefile,v 1.10 2013/01/31 21:45:04 adam Exp $

.include "../../devel/gettext/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-asprintf-/}
COMMENT=	Provides a printf-like interface for C++

DISTINFO_FILE=	${.CURDIR}/../../devel/gettext/distinfo
PATCHDIR=	${.CURDIR}/../../devel/gettext/patches

CONFIGURE_DIRS=		gettext-runtime
BUILD_DIRS=		gettext-runtime/libasprintf

USE_LANGUAGES=		c c++
INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
