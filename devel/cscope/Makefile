# $NetBSD: Makefile,v 1.54 2012/10/31 11:16:48 asau Exp $

DISTNAME=	cscope-15.8a
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cscope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cscope.sourceforge.net/
COMMENT=	Interactive C program browser
LICENSE=	original-bsd

GNU_CONFIGURE=		YES
USE_TOOLS+=		byacc lex

CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_PREFIX.ncurses}
CONFIGURE_ARGS+=	--with-flex --with-yacc
INSTALLATION_DIRS+=	share/emacs/site-lisp

SUBST_CLASSES+=		path
SUBST_SED.path=		-e "s,PATH=\"\\(.*\\),PATH=\"${PREFIX}/bin:\\1,"
SUBST_FILES.path=	contrib/xcscope/cscope-indexer
SUBST_MESSAGE.path=	Fixing path in cscope-indexer.
SUBST_STAGE.path=	post-patch

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/xcscope/cscope-indexer \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/contrib/xcscope/xcscope.el \
		${DESTDIR}${PREFIX}/share/emacs/site-lisp

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
