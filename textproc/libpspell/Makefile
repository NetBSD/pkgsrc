# $NetBSD: Makefile,v 1.1.1.1 2000/10/22 09:30:43 rh Exp $
#

DISTNAME=	pspell-.11.2
PKGNAME=	lib${DISTNAME:S/-./-0./}
CATEGORIES=	textproc devel
MASTER_SITES=	http://download.sourceforge.net/pspell/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://pspell.sourceforge.net/

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--enable-doc-dir=${PREFIX}/share/doc/pspell

.include "../../mk/bsd.pkg.mk"
