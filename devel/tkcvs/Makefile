# $NetBSD: Makefile,v 1.36 2007/06/08 18:39:24 wiz Exp $
#

DISTNAME=	tkcvs_7_2_1
PKGNAME=	tkcvs-7.2.1
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tkcvs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
