# $NetBSD: Makefile,v 1.65 2022/07/02 16:53:29 ryoon Exp $
#

DISTNAME=		vym-2.7.1
PKGREVISION=		21
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vym/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.insilmaril.de/vym/
COMMENT=		Generate and manipulate maps which show your thoughts
LICENSE=		gnu-gpl-v2

EXTRACT_USING=		bsdtar

DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils

USE_LANGUAGES=		c++
USE_TOOLS+=		perl:run bash:run

REPLACE_BASH+=		scripts/makedist-vym scripts/vivym
REPLACE_BASH+=		scripts/getbinaries scripts/screencast

REPLACE_RUBY+=		scripts/jigger
REPLACE_RUBY+=		scripts/make-qrc.rb

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

.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
