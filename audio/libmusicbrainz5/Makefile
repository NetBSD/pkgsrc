# $NetBSD: Makefile,v 1.10 2016/03/09 11:29:46 tnn Exp $

DISTNAME=	libmusicbrainz-5.1.0
PKGNAME=	${DISTNAME:S/brainz/brainz5/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=metabrainz/}
GITHUB_PROJECT=	libmusicbrainz
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/libmusicbrainz
COMMENT=	MusicBrainz (user-maintained community music metadatabase) library v5
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	libmusicbrainz5.pc.cmake

LDFLAGS.SunOS+=	-lintl

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.neon+=	neon>=0.25.0
.include "../../www/neon/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
