# $NetBSD: Makefile,v 1.7 1999/12/08 15:29:18 bouyer Exp $

DISTNAME=		fileutils-3.16
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=fileutils/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/fileutils/fileutils.html

USE_GTEXINFO=		yes
NO_PATCH=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-prefix=g

.include "../../mk/bsd.pkg.mk"
.if ${OPSYS} == "SunOS"
PLIST_SUBST+=	LOCALBASE=lib
.else
PLIST_SUBST+=	LOCALBASE=share
.endif
