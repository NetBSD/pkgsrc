# $NetBSD: Makefile,v 1.12 2010/08/12 10:22:40 asau Exp $

DISTNAME=	tinyscheme1.39
PKGNAME=	tinyscheme-1.39
CATEGORIES=	lang
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=tinyscheme/)
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tinyscheme.sourceforge.net/home.html
COMMENT=	R5RS small embeddable scheme implementation
LICENSE=	modified-bsd

MAKE_FILE=	makefile
USE_LIBTOOL=	yes

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin include lib share/tinyscheme

.include "../../mk/bsd.pkg.mk"
