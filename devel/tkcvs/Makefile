# $NetBSD: Makefile,v 1.39 2013/08/21 10:14:54 shattered Exp $
#

DISTNAME=	tkcvs-8.2.3
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tkcvs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.twobarleycorns.net/tkcvs.html
COMMENT=	Tcl/Tk frontends to CVS and diff

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	tk>=8.4:../../x11/tk

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# empty

do-install:
	(cd ${WRKSRC} && ./doinstall.tcl ${DESTDIR}${PREFIX})

.include "../../mk/bsd.pkg.mk"
