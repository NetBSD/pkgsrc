# $NetBSD: Makefile,v 1.26 2007/10/16 00:45:52 tnn Exp $

DISTNAME=	findutils-4.2.31
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=findutils/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/findutils/findutils.html
COMMENT=	The GNU find, xargs and locate utilities

GNU_CONFIGURE=		YES
INFO_FILES=		YES
PKG_DESTDIR_SUPPORT=	user-destdir
USE_PKGLOCALEDIR=	YES

LDFLAGS.IRIX+=		-lgen

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
