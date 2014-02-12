# $NetBSD: Makefile,v 1.32 2014/02/12 23:18:16 tron Exp $
#

DISTNAME=		vym-2.2.4
PKGREVISION=		8
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vym/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.insilmaril.de/vym/
COMMENT=		Generate and manipulate maps which show your thoughts
LICENSE=		gnu-gpl-v2

DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils

USE_LANGUAGES=		c++
USE_TOOLS+=		perl:run bash:run

REPLACE_PERL+=		scripts/exportvym scripts/niceXML
REPLACE_BASH+=		scripts/release-mac scripts/update-bookmarks \
			scripts/makedist-vym scripts/vivym

CHECK_INTERPRETER_SKIP=	share/vym/scripts/bugger \
			share/vym/scripts/vym-addmail.rb

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

SUBST_CLASSES+=		flags
SUBST_STAGE.flags=	pre-configure
SUBST_MESSAGE.flags=	Fix path to flags
SUBST_FILES.flags=	main.cpp
SUBST_VARS.flags=	PREFIX

post-extract:
	${CHMOD} a-x ${WRKSRC}/icons/vym.ico

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QTDIR}/bin/qmake -unix \
		PREFIX=${PREFIX} \
		DATADIR=${PREFIX}/share \
		DOCDIR=${PREFIX}/doc/vym vym.pro

.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
