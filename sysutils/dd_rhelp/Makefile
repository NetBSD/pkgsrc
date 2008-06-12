# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:46 joerg Exp $

DISTNAME=		dd_rhelp-0.0.6
CATEGORIES=		sysutils
MASTER_SITES=		http://www.kalysto.org/pkg/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.kalysto.org/utilities/dd_rhelp/index.en.html
COMMENT=		Rescue hard disk helper

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

USE_TOOLS+=		bash:run

# can't use REPLACE_INTERPRETER because it happens too early
SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	post-build
SUBST_FILES.bash=	dd_rhelp
SUBST_SED.bash=		-e 's,^\#!.*/bash,\#!${TOOLS_PATH.bash},'

DEPENDS+=		dd_rescue>=1.03:../../sysutils/dd_rescue

.include "../../mk/bsd.pkg.mk"
