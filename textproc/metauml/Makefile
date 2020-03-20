# $NetBSD: Makefile,v 1.6 2020/03/20 11:58:28 nia Exp $
#

DISTNAME=	metauml_lib_0.2.5
PKGNAME=	${DISTNAME:S/_lib_/-/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=metauml/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://metauml.sourceforge.net/
COMMENT=	MetaPost library for typesetting UML diagrams

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PKGBASE}_lib
MPDIR=		share/texmf-dist/metapost/${PKGBASE}

INSTALLATION_DIRS+=	${MPDIR}

.include "../../print/kpathsea/texmf.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/thrunk/*.mp ${DESTDIR}${PREFIX}/${MPDIR}

.include "../../mk/bsd.pkg.mk"
