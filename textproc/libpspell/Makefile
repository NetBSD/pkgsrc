# $NetBSD: Makefile,v 1.8 2002/10/08 12:20:38 wiz Exp $
#

DISTNAME=	pspell-.12.2
PKGNAME=	lib${DISTNAME:S/-./-0./}
PKGREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pspell/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://pspell.sourceforge.net/
COMMENT=	generic interface to spell checker libraries

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--enable-doc-dir=${PREFIX}/share/doc/pspell

.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
