# $NetBSD: Makefile,v 1.6.2.1 2002/06/30 06:24:19 jlam Exp $
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

.include "../../mk/bsd.pkg.mk"
