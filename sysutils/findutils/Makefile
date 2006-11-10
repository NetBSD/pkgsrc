# $NetBSD: Makefile,v 1.25 2006/11/10 14:44:33 tv Exp $

DISTNAME=	findutils-4.1
PKGREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=findutils/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/findutils/findutils.html
COMMENT=	The GNU find, xargs and locate utilities

GNU_CONFIGURE=		YES
CONFIGURE_HAS_INFODIR=	NO
CONFIGURE_HAS_MANDIR=	NO
MAKE_FLAGS+=		infodir=${GNU_CONFIGURE_INFODIR:Q}
MAKE_FLAGS+=		mandir=${GNU_CONFIGURE_MANDIR:Q}
LDFLAGS.IRIX+=		-lgen

INFO_FILES=		# PLIST

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
