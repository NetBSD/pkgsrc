# $NetBSD: Makefile,v 1.15 2003/12/13 16:36:21 seb Exp $
#

DISTNAME=	sed-4.0.8
PKGNAME=	g${DISTNAME}
CATEGORIES=	textproc editors
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sed/sed.html
COMMENT=	GNU implementation of sed, the POSIX stream editor

USE_BUILDLINK2=		YES
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

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
