# $NetBSD: Makefile,v 1.15 2001/06/20 03:22:17 jlam Exp $

DISTNAME=	cscope-15.0bl2
PKGNAME=	cscope-15.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cscope/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cscope.sourceforge.net/
COMMENT=	interactive C program browser

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_DIR}

# Change references to <curses.h> to <ncurses.h> in the source files.
NCURSES_SED=		-e "s|<curses.h>|<ncurses.h>|g"

post-extract:
	cd ${WRKSRC}/src; for file in *.[ch]; do			\
		${MV} -f $${file} $${file}.presubst;			\
		${SED} ${NCURSES_SED} $${file}.presubst > $${file};	\
		${RM} -f $${file}.presubst;				\
	done

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
