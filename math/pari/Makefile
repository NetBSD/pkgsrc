# $NetBSD: Makefile,v 1.9 2001/11/30 01:18:12 wiz Exp $

DISTNAME=		pari-2.1.1
CATEGORIES=		math
MASTER_SITES=		ftp://www.gn-50uma.de/gn/gn-50uma.de/pari-2.1/ \
			http://www.gn-50uma.de/ftp/pari-2.1/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.parigp-home.de
COMMENT=		software package for computer-aided number theory

BUILD_DEPENDS+= 	teTeX-[0-9]*:../../print/teTeX
BUILD_DEPENDS+= 	emacs-[0-9]*:../../editors/emacs

USE_PERL5=		yes

USE_BUILDLINK_ONLY=	yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${WRKSRC}/Configure

# rl_save_prompt
USE_GNU_READLINE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX} --share-prefix=${PREFIX}/share

CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
CONFIGURE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}

CONFIGURE_ARGS+=	--graphic=X11

.include "../../devel/ncurses/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
