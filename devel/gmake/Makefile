# $NetBSD: Makefile,v 1.44 2003/04/22 20:25:10 wiz Exp $

DISTNAME=	make-3.80
PKGNAME=	gmake-3.80
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=make/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/make/make.html
COMMENT=	GNU version of 'make' utility

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
TEXINFO_OVERRIDE=	YES
TEXINFO_REQD=		4.0

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

# NOTE:  the 'test' target requires perl, but since gmake does
# not otherwise require it, perl is not listed as an explicit
# dependency
test: build
	cd ${WRKSRC} && \
		${MAKE_ENV} ${MAKE_PROGRAM} check 2>&1 | \
		tee ${WRKDIR}/tests.log

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
