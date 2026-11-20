# $NetBSD: Makefile,v 1.42 2026/11/20 15:57:10 ktnb Exp $

DISTNAME=	pinfo-0.6.13
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=baszoetekouw/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/baszoetekouw/pinfo/
COMMENT=		Przemek's Info Viewer
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt autoconf automake autopoint gettext makeinfo
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/pinfo
CONF_FILES=		${EGDIR}/pinforc ${PKG_SYSCONFDIR}/pinforc
INFO_FILES=		yes
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

SUBST_CLASSES+=		infopath
SUBST_STAGE.infopath=	pre-configure
SUBST_FILES.infopath=	src/datatypes.c
SUBST_SED.infopath=	-e 's,= "\.:/usr/share/info,= ".:/usr/share/info:${PREFIX}/${PKGINFODIR}:${X11BASE}/${PKGINFODIR}:${LOCALBASE}/${PKGINFODIR}:/usr/local/info,'

pre-configure:
	cd ${WRKSRC} && autoreconf -fi -I macros

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
