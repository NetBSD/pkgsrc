# $NetBSD: Makefile,v 1.9 2003/06/14 00:04:55 grant Exp $
#

DISTNAME=	sed-4.0.7
PKGNAME=	g${DISTNAME}
CATEGORIES=	textproc editors
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}

MAINTAINER=	seb@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/sed/sed.html
COMMENT=	GNU version of sed

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

INFO_FILES=	sed.info

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=        --program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=           GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=            GNU_PROGRAM_PREFIX

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
