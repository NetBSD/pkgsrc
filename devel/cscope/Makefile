# $NetBSD: Makefile,v 1.26 2003/07/21 16:43:17 martti Exp $
#

DISTNAME=	cscope-15.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cscope/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cscope.sourceforge.net/
COMMENT=	Interactive C program browser

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
