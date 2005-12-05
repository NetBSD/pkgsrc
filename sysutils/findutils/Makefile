# $NetBSD: Makefile,v 1.21 2005/12/05 23:55:19 rillig Exp $

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
MAKE_ENV+=		INFO_DIR=${INFO_DIR:Q}
LDFLAGS.IRIX+=		-lgen

INFO_FILES=		find.info

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "IRIX"
PLIST_SUBST+=	USE_CATMAN="@comment "
.else
PLIST_SUBST+=	USE_CATMAN=""
.endif

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
