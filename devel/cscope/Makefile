# $NetBSD: Makefile,v 1.21 2003/03/22 06:05:26 wiz Exp $
#

DISTNAME=	cscope-15.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cscope/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cscope.sourceforge.net/
COMMENT=	interactive C program browser

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_PREFIX.ncurses}
CONFIGURE_ARGS+=	--with-flex

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=		flex-*:../../devel/flex
LEX=			${LOCALBASE}/bin/flex
.endif

CONFIGURE_ENV+=		LEX=${LEX}

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
