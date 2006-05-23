# $NetBSD: Makefile,v 1.3 2006/05/23 13:00:50 joerg Exp $

DISTNAME=		gettext-0.14.5
PKGNAME=		gettext-asprintf-0.14.5
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		Provides a printf-like interface for C++

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/gettext-runtime

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

BUILD_DIRS=		libasprintf

INFO_DIRS=		# PLIST

.include "../../mk/bsd.pkg.mk"
