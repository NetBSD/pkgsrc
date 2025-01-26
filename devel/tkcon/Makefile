# $NetBSD: Makefile,v 1.2 2025/01/26 12:14:14 gdt Exp $

DISTNAME=	tkcon-2.7.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=wjoye/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wjoye/tkcon/
COMMENT=	Enhanced Tk Console for all Tk platforms
LICENSE=	esdl-license
# doc/license.terms also contains "bourbon_ware clause v2", which is a
# declaration that donations are appreciated, rather than a license
# or a modification of terms.

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
