# $NetBSD: Makefile,v 1.1.1.1 2008/02/01 20:41:37 tonio Exp $
#

DISTNAME=	metauml_lib_0.2.5
PKGNAME=	${DISTNAME:S/_lib_/-/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=metauml/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://metauml.sourceforge.net/
COMMENT=	MetaPost library for typesetting UML diagrams

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PKGBASE}_lib
MPDIR=		${PKG_LOCALTEXMFPREFIX}/metapost/${PKGBASE}
PLIST_SUBST+=	MPDIR=${MPDIR:C|^${PREFIX}/||}
INSTALLATION_DIRS+=	${MPDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/thrunk/*.mp ${MPDIR}

.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
