# $NetBSD: Makefile,v 1.4 2002/01/15 01:05:14 wiz Exp $
#

DISTNAME=	pspell-.12.2
PKGNAME=	lib${DISTNAME:S/-./-0./}
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pspell/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://pspell.sourceforge.net/
COMMENT=	generic interface to spell checker libraries

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--enable-doc-dir=${PREFIX}/share/doc/pspell
USE_BUILDLINK_ONLY=	YES

.include "../../devel/libtool/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
