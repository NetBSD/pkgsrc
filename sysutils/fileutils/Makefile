# $NetBSD: Makefile,v 1.9 2000/10/04 11:04:57 toshii Exp $

DISTNAME=		fileutils-3.16
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=fileutils/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/fileutils/fileutils.html

USE_GTEXINFO=		yes
NO_PATCH=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-prefix=g

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
PLIST_SUBST+=	LOCALEBASE=lib
.else
PLIST_SUBST+=	LOCALEBASE=share
.endif

.include "../../mk/bsd.pkg.mk"
