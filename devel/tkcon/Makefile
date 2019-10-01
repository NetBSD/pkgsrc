# $NetBSD: Makefile,v 1.1 2019/10/01 23:40:40 kamil Exp $

DISTNAME=	tkcon-2.7.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=wjoye/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wjoye/tkcon/
COMMENT=	Enhanced Tk Console for all Tk platforms
#LICENSE=	# esdl-license like with bourbon_ware clause v2

USE_TOOLS+=	wish:run

SUBST_CLASSES+=		fix-wish
SUBST_STAGE.fix-wish=	pre-configure
SUBST_MESSAGE.fix-wish=	Fixing tcl wish
SUBST_FILES.fix-wish+=	${PKGBASE}.tcl
SUBST_SED.fix-wish+=	-e 's,exec wish,exec ${PREFIX}/bin/wish,'

#DEPENDS+=	xhost-[0-9]*:../../x11/xhost # Not important?

GNU_CONFIGURE=	yes # Not important?

INSTALLATION_DIRS+=	bin

do-install:
	${RUN}cd ${WRKSRC} && \
		${INSTALL_SCRIPT} ${PKGBASE}.tcl \
			${DESTDIR}${PREFIX}/bin/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
