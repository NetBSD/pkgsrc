# $NetBSD: Makefile,v 1.19.2.1 2012/10/03 12:08:50 spz Exp $
#

DISTNAME=		vym-1.12.7
PKGREVISION=		11
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vym/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vym.sourceforge.net/
COMMENT=		Generate and manipulate maps which show your thoughts
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c++
USE_TOOLS+=		perl:run bash:run

REPLACE_PERL+=		scripts/exportvym scripts/niceXML
REPLACE_BASH+=		scripts/release-mac scripts/update-bookmarks

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

post-extract:
	${CHMOD} a-x ${WRKSRC}/icons/vym.ico

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QTDIR}/bin/qmake -unix PREFIX=${PREFIX} vym.pro

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
