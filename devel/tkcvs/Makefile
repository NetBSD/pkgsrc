# $NetBSD: Makefile,v 1.42 2026/02/14 08:28:40 wiz Exp $

DISTNAME=	tkcvs-8.2.3
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tkcvs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/tkcvs/
COMMENT=	Tcl/Tk frontends to CVS and diff

DEPENDS+=	tk>=8.4:../../x11/tk

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# empty

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-install
SUBST_FILES.manpath=	doinstall.tcl
SUBST_SED.manpath=	-e 's, man , ${PKGMANDIR} ,g'

do-install:
	(cd ${WRKSRC} && ./doinstall.tcl ${DESTDIR}${PREFIX})

.include "../../mk/bsd.pkg.mk"
