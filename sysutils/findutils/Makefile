# $NetBSD: Makefile,v 1.12 2004/05/04 02:07:06 snj Exp $

DISTNAME=	findutils-4.1
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=findutils/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/findutils/findutils.html
COMMENT=	The GNU find, xargs and locate utilities

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

INFO_FILES=		find.info

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS=		--program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
