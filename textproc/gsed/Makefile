# $NetBSD: Makefile,v 1.22 2005/03/01 23:10:47 dmcmahill Exp $
#

DISTNAME=	sed-4.1.1
PKGNAME=	g${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc editors
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sed/sed.html
COMMENT=	GNU implementation of sed, the POSIX stream editor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIG_STATUS_OVERRIDE=	# empty

# at least Solaris-2.9 has issues with grep/egrep
USE_GNU_TOOLS+=		grep

INFO_FILES=		sed.info

TEST_TARGET=		check
.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=        --program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=           GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=            GNU_PROGRAM_PREFIX

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
