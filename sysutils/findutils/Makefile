# $NetBSD: Makefile,v 1.18 2005/10/04 18:31:29 reed Exp $

DISTNAME=	findutils-4.1
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=findutils/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/findutils/findutils.html
COMMENT=	The GNU find, xargs and locate utilities

GNU_CONFIGURE=		YES
CONFIGURE_HAS_INFODIR=	NO
CONFIGURE_HAS_MANDIR=	NO
MAKE_ENV+=		INFO_DIR=${INFO_DIR}

INFO_FILES=		find.info

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
