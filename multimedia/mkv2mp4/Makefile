# $NetBSD: Makefile,v 1.11 2011/11/16 01:33:18 sbd Exp $
#

SVNREV=		11
DISTNAME=	mkv2mp4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}-0.0alpha${SVNREV}
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://mkv2mp4.googlecode.com/svn-history/r${SVNREV}/trunk/
NO_BUILD=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

DISTFILES=	${DISTNAME}.py README
DIST_SUBDIR=	mkv2mp4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/mkv2mp4
COMMENT=	Remux mkv files to mp4 files compatible with standalone players
WRKSRC=		${WRKDIR}

REPLACE_PYTHON=	${DISTNAME}.py
# uses subprocess.check_call, which is new in 2.5
PYTHON_VERSIONS_ACCEPTED=	25 27 26

INSTALLATION_DIRS=	bin share/doc/mkv2mp4

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.py \
	    ${DESTDIR}${PREFIX}/bin/${DISTNAME}.py
	${INSTALL_DATA} ${WRKSRC}/README \
	    ${DESTDIR}${PREFIX}/share/doc/${DISTNAME}/README

.include "../../lang/python/application.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/gpac/buildlink3.mk"
DEPENDS+=	mkvtoolnix>=1.7.0:../../multimedia/mkvtoolnix
.include "../../mk/bsd.pkg.mk"
