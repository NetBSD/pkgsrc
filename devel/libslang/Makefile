# $NetBSD: Makefile,v 1.67 2009/06/13 06:46:42 rillig Exp $
#

DISTNAME=	slang-1.4.9
PKGNAME=	lib${DISTNAME}
SVR4_PKGNAME=	lslan
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v1.4/ \
		http://gd.tuwien.ac.at/editors/davis/slang/v1.4/ \
		ftp://ftp.ntua.gr/pub/lang/slang/slang/v1.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.s-lang.org/
COMMENT=	Routines for rapid alpha-numeric terminal applications development

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
DLOPEN_REQUIRE_PTHREADS=no

.include "../../mk/termcap.buildlink3.mk"

.if ${TERMCAP_TYPE} == "termcap"
CONFIGURE_ENV+=		TERMCAP=${BUILDLINK_LDADD.termcap:Q}
CONFIGURE_ENV+=		MISC_TERMINFO_DIRS=${PREFIX:Q}/share/terminfo
.else
CONFIGURE_ENV+=		TERMCAP=
CONFIGURE_ENV+=		MISC_TERMINFO_DIRS=${BUILDLINK_PREFIX.termcap:Q}/share/terminfo
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
