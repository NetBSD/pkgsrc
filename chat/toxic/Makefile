# $NetBSD: Makefile,v 1.5 2025/10/05 19:25:43 js Exp $

DISTNAME=	toxic-0.16.1
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=JFreegman/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/JFreegman/toxic/
COMMENT=	Terminal-based Tox peer-to-peer messenger
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

MAKE_ENV+=	ENABLE_RELEASE=1
.include "../../mk/bsd.prefs.mk"
# on Darwin there are many X11 errors
.if ${OPSYS} == "Darwin"
MAKE_ENV+=     DISABLE_X11=1
.endif
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/

SUBST_CLASSES+=                prefix
SUBST_SED.prefix+=     -e "s,/usr/local/opt/freealut/include,${PREFIX}/include,"
SUBST_SED.prefix+=     -e "s,/usr/local/opt/glib/include,${PREFIX}/include,"
SUBST_SED.prefix+=     -e "s,PKG_CONFIG_PATH,\# PKG_CONFIG_PATH,"
SUBST_FILES.prefix+=   cfg/systems/Darwin.mk
SUBST_STAGE.prefix=    pre-configure
SUBST_MESSAGE.prefix=  Adapt hardcoded prefix for pkgsrc.

INSTALLATION_DIRS+=	man/man1 man/man5

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/toxic.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/toxic.conf.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	# the install target puts gzipped man pages here
	${RM} -r ${DESTDIR}${PREFIX}/share/man

.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
BUILDLINK_API_DEPENDS.toxcore+=	toxcore>=0.2.21
.include "../../chat/toxcore/buildlink3.mk"
.include "../../converters/qrencode/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
# segfaults without direct bl3 to ncurses
.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
