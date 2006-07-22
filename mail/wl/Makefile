# $NetBSD: Makefile,v 1.29 2006/07/22 17:26:59 rpaulo Exp $

DISTNAME=	wl-2.14.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.gohome.org/wl/stable/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.gohome.org/wl/
COMMENT=	Mail/news management system with IMAP4rev1 support for Emacs

.include "../../mk/emacs.mk"

# apel and bbdb are included in xemacs-packages
.if ${EMACS_FLAVOR} == "emacs"
DEPENDS+=	${EMACS_PKGNAME_PREFIX}apel>=10.6:../../devel/apel
DEPENDS+=       ${EMACS_PKGNAME_PREFIX}bbdb-[0-9]*:../../misc/bbdb
.endif
DEPENDS+=	${EMACS_PKGNAME_PREFIX}flim>=1.14.7:../../devel/flim
DEPENDS+=	${EMACS_PKGNAME_PREFIX}semi>=1.14.6:../../devel/semi

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20 xemacs214

BUILD_TARGET=	all info
INSTALL_TARGET=	install install-info
MAKE_FLAGS+=	INFODIR=${EMACS_INFOPREFIX:Q}
MAKE_FLAGS+=	LISPDIR=${EMACS_LISPPREFIX:Q}
MAKE_FLAGS+=	EMACS=${EMACS_FLAVOR:Q}
MAKE_FLAGS+=	PIXMAPDIR=${PREFIX:Q}/share/wl
INFO_FILES=	# PLIST


DOCDIR=			${PREFIX}/share/doc/wl
EXAMPLESDIR=		${PREFIX}/share/examples/wl
INSTALLATION_DIRS=	${DOCDIR} ${EXAMPLESDIR} ${EMACS_INFOPREFIX}

.include "../../security/openssl/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR:Q}/en
	${INSTALL_DATA_DIR} ${DOCDIR:Q}/ja
	@set -e; \
	for f in BUGS NEWS README; do \
		${INSTALL_DATA} ${WRKSRC:Q}/"$$f" ${DOCDIR:Q}/en; \
		${INSTALL_DATA} ${WRKSRC:Q}/"$$f".ja ${DOCDIR:Q}/ja; \
	done
	${INSTALL_DATA_DIR} ${EXAMPLESDIR:Q}/en
	${INSTALL_DATA_DIR} ${EXAMPLESDIR:Q}/ja
	${INSTALL_DATA} ${WRKSRC:Q}/samples/en/dot.* ${EXAMPLESDIR:Q}/en
	${INSTALL_DATA} ${WRKSRC:Q}/samples/ja/dot.* ${EXAMPLESDIR:Q}/ja

.include "../../mk/bsd.pkg.mk"
