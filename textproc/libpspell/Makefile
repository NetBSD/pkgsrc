# $NetBSD: Makefile,v 1.2 2000/11/11 17:49:28 tron Exp $
#

DISTNAME=	pspell-.11.2
PKGNAME=	lib${DISTNAME:S/-./-0./}
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pspell/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://pspell.sourceforge.net/

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--enable-doc-dir=${PREFIX}/share/doc/pspell

.include "../../mk/bsd.pkg.mk"
