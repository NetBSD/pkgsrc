# $NetBSD: Makefile,v 1.2 2009/07/07 21:08:34 joerg Exp $
#

DISTNAME=	metauml_lib_0.2.5
PKGNAME=	${DISTNAME:S/_lib_/-/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=metauml/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://metauml.sourceforge.net/
COMMENT=	MetaPost library for typesetting UML diagrams

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PKGBASE}_lib
MPDIR=		${PKG_LOCALTEXMFPREFIX}/metapost/${PKGBASE}
PLIST_SUBST+=	MPDIR=${MPDIR:C|^${PREFIX}/||}
INSTALLATION_DIRS+=	${MPDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/thrunk/*.mp ${DESTDIR}${MPDIR}

.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
