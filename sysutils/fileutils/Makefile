# $NetBSD: Makefile,v 1.12 2001/02/17 17:42:12 wiz Exp $

DISTNAME=		fileutils-3.16
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=fileutils/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/fileutils/fileutils.html
COMMENT=		GNU file management utilities

USE_GTEXINFO=		yes
NO_PATCH=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-prefix=g

PLIST_SUBST+=		LOCALEDIR=${LOCALEDIR}

.include "../../mk/bsd.pkg.mk"
