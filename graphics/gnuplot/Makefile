# $NetBSD: Makefile,v 1.183 2024/01/30 14:22:09 ryoon Exp $

DISTNAME=	gnuplot-5.4.10
CATEGORIES+=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnuplot.info/
COMMENT=	Portable interactive, function plotting utility
PKGREVISION=	1
#LICENSE=	gnuplot + BSD

API_VERSION=	${PKGVERSION_NOREV:C/([0-9])\.([0-9])\.([0-9])+/\1.\2/}

CONFLICTS+=		gnuplot-nox11-[0-9]*

USE_LANGUAGES=		c
USE_TOOLS+=		makeinfo pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-latex
CONFIGURE_ARGS+=	ac_cv_prog_EMACS=
INFO_FILES=		yes
TEST_TARGET=		check

PLIST_SUBST+=		API_VERSION=${API_VERSION}

.include "options.mk"

.include "../../mk/readline.buildlink3.mk"
.if   ${READLINE_TYPE} == "editline"
CONFIGURE_ARGS+=	--with-readline=bsd
.elif ${READLINE_TYPE} == "readline"
CONFIGURE_ARGS+=	--with-readline=gnu
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
