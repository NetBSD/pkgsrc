# $NetBSD: Makefile,v 1.52 2004/01/05 11:18:13 jlam Exp $

DISTNAME=	make-3.80
PKGNAME=	gmake-3.80
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=make/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/make/make.html
COMMENT=	GNU version of 'make' utility

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
TEXINFO_REQD=		4.0
INFO_FILES=		make.info

# NOTE:  the 'test' target requires perl, but since gmake does
# not otherwise require it, perl is not listed as an explicit
# dependency
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.if !defined(GNU_PROGRAM_PREFIX) || ${GNU_PROGRAM_PREFIX} != "g"
PLIST_SUBST+=		GMAKE_LINK=""
.else
PLIST_SUBST+=		GMAKE_LINK="@comment "
.endif

post-install:
	${CHMOD} g-s ${PREFIX}/bin/${GNU_PROGRAM_PREFIX}make
	${CHGRP} ${BINGRP} ${PREFIX}/bin/${GNU_PROGRAM_PREFIX}make
.if !defined(GNU_PROGRAM_PREFIX) || ${GNU_PROGRAM_PREFIX} != "g"
	${LN} -sf ${GNU_PROGRAM_PREFIX}make ${PREFIX}/bin/gmake
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
