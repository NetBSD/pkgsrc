# $NetBSD: Makefile,v 1.1.1.1 2006/02/04 16:53:56 joerg Exp $

DISTNAME=		gettext-0.14.5
PKGNAME=		gettext-asprintf-0.14.5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		Provides a printf-like interface for C++

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/gettext-runtime

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

BUILD_DIRS=		libasprintf

.include "../../mk/bsd.pkg.mk"
