# $NetBSD: Makefile,v 1.11 2002/09/23 22:24:16 jlam Exp $

DISTNAME=		pari-2.1.1
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		ftp://www.gn-50uma.de/gn/gn-50uma.de/pari-2.1/ \
			http://www.gn-50uma.de/ftp/pari-2.1/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.parigp-home.de
COMMENT=		software package for computer-aided number theory

BUILD_DEPENDS+= 	teTeX-[0-9]*:../../print/teTeX
BUILD_DEPENDS+= 	emacs-[0-9]*:../../editors/emacs

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GNU_READLINE=	# rl_save_prompt

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${WRKSRC}/Configure
CONFIGURE_ARGS+=	--prefix=${PREFIX} --share-prefix=${PREFIX}/share
CONFIGURE_ARGS+=	--graphic=X11
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
CONFIGURE_ENV+=		X11BASE=${X11BASE}

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
