# $NetBSD: Makefile,v 1.17 2022/01/10 18:32:50 wiz Exp $

DISTNAME=	pyid3lib-0.5.1
PKGNAME=	${PYPKGPREFIX}-id3lib-0.5.1
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyid3lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyid3lib.sourceforge.net/
COMMENT=	Python module for editing ID3v2 tags of MP3 audio files
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.5.1

.include "../../lang/python/egg.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
