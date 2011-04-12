# $NetBSD: Makefile,v 1.9 2011/04/12 17:41:28 adam Exp $

.include "../../devel/gettext/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-asprintf-/}
COMMENT=	Provides a printf-like interface for C++

CONFIGURE_DIRS=		gettext-runtime
BUILD_DIRS=		gettext-runtime/libasprintf

USE_LANGUAGES=		c c++
INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
