# $NetBSD: Makefile,v 1.19 2024/05/06 08:27:52 jperkin Exp $

DISTNAME=	mg-20230501
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=hboetes/}
GITHUB_PROJECT=	mg
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://github.com/hboetes/mg
COMMENT=	Small, fast, public domain EMACS style editor

#FAKE_NCURSES=	yes
USE_TOOLS+=	install gmake pkg-config
MAKE_ENV+=	prefix=${PREFIX}
MAKE_FILE=	GNUmakefile

CFLAGS.NetBSD+=	-D_OPENBSD_SOURCE

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/${PKGBASE}

CONFLICTS+=	mg2a-[0-9]*

BUILDLINK_TRANSFORM+=	rm:-Werror

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Adjusting path.
SUBST_FILES.path=	GNUmakefile mg.1
SUBST_SED.path=		-e "s|/usr/local|${PREFIX}|g"
SUBST_SED.path+=	-e "s|/usr/share/doc|${PREFIX}/share/doc|g"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
post-extract:
	cp ${FILESDIR}/tree.h ${WRKSRC}
.endif

pre-install:
	${INSTALL_DATA} ${WRKSRC}/tutorial ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/tutorial

.if ${OPSYS} == "Linux"
.include "../../devel/libbsd/buildlink3.mk"
.endif
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
