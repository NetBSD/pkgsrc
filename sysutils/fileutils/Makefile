# $NetBSD: Makefile,v 1.10 2001/01/10 13:22:16 tron Exp $

DISTNAME=		fileutils-3.16
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=fileutils/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/fileutils/fileutils.html

USE_GTEXINFO=		yes
NO_PATCH=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-prefix=g

PLIST_SUBST+=		LOCALEBASE=${LOCALEBASE}

.include "../../mk/bsd.pkg.mk"
