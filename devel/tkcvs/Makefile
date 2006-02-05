# $NetBSD: Makefile,v 1.33 2006/02/05 23:08:54 joerg Exp $
#

DISTNAME=	tkcvs_7_2_1
PKGNAME=	tkcvs-7.2.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.twobarleycorns.net/ \
		${MASTER_SITE_SOURCEFORGE:=tkcvs/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.twobarleycorns.net/tkcvs.html
COMMENT=	Tcl/Tk frontends to CVS and diff

DEPENDS+=	tk>=8.4:../../x11/tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# empty

do-install:
	(cd ${WRKSRC} && ./doinstall.tcl ${PREFIX})

.include "../../mk/bsd.pkg.mk"
