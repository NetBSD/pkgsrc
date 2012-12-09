# $NetBSD: Makefile,v 1.16 2012/12/09 08:15:58 ryoon Exp $
#

DISTNAME=	mkv2mp4-20121208
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-/-0.0./}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dfwarden/mkv2mp4
COMMENT=	Remux mkv files to mp4 files compatible with standalone players
LICENSE=	gnu-gpl-v3

NO_BUILD=	yes

REPLACE_PYTHON=	mkv2mp4.py

INSTALLATION_DIRS=	bin share/doc/mkv2mp4

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mkv2mp4.py \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README* \
	    ${DESTDIR}${PREFIX}/share/doc/mkv2mp4
	${INSTALL_DATA} ${WRKSRC}/COPYING \
	    ${DESTDIR}${PREFIX}/share/doc/mkv2mp4

.include "../../lang/python/application.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/gpac/buildlink3.mk"
DEPENDS+=	mkvtoolnix>=1.7.0:../../multimedia/mkvtoolnix
.include "../../mk/bsd.pkg.mk"
