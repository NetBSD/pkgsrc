# $NetBSD: Makefile,v 1.34 2024/01/30 14:22:31 ryoon Exp $

DISTNAME=	xca-2.1.2
PKGREVISION=	32
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=chris2511/}
GITHUB_RELEASE=	RELEASE.2.1.2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hohnstaedt.de/xca/
COMMENT=	Certificate and key management
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config perl
USE_LANGUAGES=		c c++
DESTDIR_VARNAME=	destdir

REPLACE_PERL+=		doc/code2html

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/applications share/mime/packages share/pixmaps
INSTALLATION_DIRS+=	share/doc/xca share/xca

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
