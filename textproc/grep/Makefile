# $NetBSD: Makefile,v 1.15 2004/04/25 05:03:43 snj Exp $
#

DISTNAME=	grep-2.5.1
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=grep/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/grep/grep.html
COMMENT=	GNU grep

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
BUILD_USES_MSGFMT=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-perl-regexp

USE_MAKEINFO=		YES
TEXINFO_REQD=		4.0
INFO_FILES=		grep.info

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
