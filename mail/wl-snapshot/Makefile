# $NetBSD: Makefile,v 1.10 2019/10/22 03:55:12 mef Exp $

DISTNAME= 	wl-beta_2.15.9+0.20190919
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/beta_//:S/+0//}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/w/wl-beta/}
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gohome.org/wl/
COMMENT=	Mail/news management system with IMAP4rev1 support for Emacs
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	patch
WRKSRC=		${WRKDIR}/wanderlust-wanderlust-7a919e4

BUILD_TARGET=	all info
INSTALL_TARGET=	install install-info
MAKE_FLAGS+=	INFODIR=${DESTDIR}${EMACS_INFOPREFIX}
MAKE_FLAGS+=	LISPDIR=${DESTDIR}${EMACS_LISPPREFIX}
MAKE_FLAGS+=	EMACS=${EMACS_BIN}
MAKE_FLAGS+=	PIXMAPDIR=${DESTDIR}${PREFIX}/share/wl
INFO_FILES=	yes

SUBST_CLASSES+=			icon_directory
SUBST_STAGE.icon_directory=	pre-configure
SUBST_MESSAGE.icon_directory=	Fixing wl-icon-directory default value (defvar)
SUBST_FILES.icon_directory=	${WRKSRC}/wl/wl-vars.el
SUBST_SED.icon_directory=	-e 's|%%PREFIX%%|${PREFIX}|'

DOCDIR=			${PREFIX}/share/doc/wl
EXAMPLESDIR=		${PREFIX}/share/examples/wl
INSTALLATION_DIRS=	${DOCDIR}/en ${DOCDIR}/ja \
			${EXAMPLESDIR}/en ${EXAMPLESDIR}/ja \
			${EMACS_INFOPREFIX}

EMACS_BUILDLINK=	# empty

.include "options.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../devel/semi/buildlink3.mk"
.include "../../editors/emacs/modules.mk"
.include "../../misc/bbdb/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

post-install:
	set -e; \
	for f in BUGS NEWS; do \
		${INSTALL_DATA} ${WRKSRC}/"$$f"    ${DESTDIR}${DOCDIR}/en; \
		${INSTALL_DATA} ${WRKSRC}/"$$f".ja ${DESTDIR}${DOCDIR}/ja; \
	done
	for f in README; do \
		${INSTALL_DATA} ${WRKSRC}/"$$f".md ${DESTDIR}${DOCDIR}/en; \
		${INSTALL_DATA} ${WRKSRC}/"$$f".ja ${DESTDIR}${DOCDIR}/ja; \
	done
	${INSTALL_DATA} ${WRKSRC}/samples/en/dot.* ${DESTDIR}${EXAMPLESDIR}/en
	${INSTALL_DATA} ${WRKSRC}/samples/ja/dot.* ${DESTDIR}${EXAMPLESDIR}/ja

.include "../../mk/bsd.pkg.mk"
