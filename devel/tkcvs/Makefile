# $NetBSD: Makefile,v 1.37 2010/01/29 19:19:49 joerg Exp $
#

DISTNAME=	tkcvs_7_2_1
PKGNAME=	tkcvs-7.2.1
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tkcvs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.twobarleycorns.net/tkcvs.html
COMMENT=	Tcl/Tk frontends to CVS and diff

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	tk>=8.4:../../x11/tk

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# empty

do-install:
	(cd ${WRKSRC} && ./doinstall.tcl ${DESTDIR}${PREFIX})

.include "../../mk/bsd.pkg.mk"
