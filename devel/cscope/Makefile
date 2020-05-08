# $NetBSD: Makefile,v 1.61 2020/05/08 16:20:38 rillig Exp $

DISTNAME=	cscope-15.8a
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cscope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cscope.sourceforge.net/
COMMENT=	Interactive C program browser
LICENSE=	original-bsd

GNU_CONFIGURE=		YES
USE_TOOLS+=		byacc lex:run

INSTALLATION_DIRS+=	share/emacs/site-lisp

SUBST_CLASSES+=		path
SUBST_SED.path=		-e "s,PATH=\"\\(.*\\),PATH=\"${PREFIX}/bin:\\1,"
SUBST_FILES.path=	contrib/xcscope/cscope-indexer
SUBST_MESSAGE.path=	Fixing path in cscope-indexer.
SUBST_STAGE.path=	pre-configure

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/xcscope/cscope-indexer \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/contrib/xcscope/xcscope.el \
		${DESTDIR}${PREFIX}/share/emacs/site-lisp

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if ${CURSES_TYPE} == "ncurses"
CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_PREFIX.ncurses}
.endif
