# $NetBSD: Makefile,v 1.1.1.1 2009/01/23 15:00:05 jmcneill Exp $
#

SVNREV=		11
DISTNAME=	mkv2mp4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}-0.0alpha${SVNREV}
CATEGORIES=	multimedia
MASTER_SITES=	http://mkv2mp4.googlecode.com/svn-history/r${SVNREV}/trunk/
NO_BUILD=	yes

DISTFILES=	${DISTNAME}.py README
DIST_SUBDIR=	mkv2mp4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mkv2mp4.googlecode.com/
COMMENT=	Remux mkv files to mp4 files compatible with standalone players
WRKSRC=		${WRKDIR}

REPLACE_PYTHON=	${DISTNAME}.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.py \
	    ${DESTDIR}${PREFIX}/bin/${DISTNAME}.py
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/README \
	    ${DESTDIR}${PREFIX}/share/doc/${DISTNAME}/README

.include "../../lang/python/application.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/gpac/buildlink3.mk"
DEPENDS+=	mkvtoolnix>=1.7.0:../../multimedia/mkvtoolnix
.include "../../mk/bsd.pkg.mk"
