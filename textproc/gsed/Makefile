# $NetBSD: Makefile,v 1.17 2004/04/25 05:01:46 snj Exp $
#

DISTNAME=	sed-4.0.9
PKGNAME=	g${DISTNAME}
CATEGORIES=	textproc editors
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sed/sed.html
COMMENT=	GNU implementation of sed, the POSIX stream editor

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

INFO_FILES=		sed.info

TEST_TARGET=		check
.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=        --program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=           GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=            GNU_PROGRAM_PREFIX

CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.iconv}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
