# $NetBSD: Makefile,v 1.37 2008/01/18 05:08:31 tnn Exp $

DISTNAME=	wl-2.14.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.gohome.org/wl/stable/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.gohome.org/wl/
COMMENT=	Mail/news management system with IMAP4rev1 support for Emacs

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

.include "../../mk/emacs.mk"

.include "options.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../devel/semi/buildlink3.mk"
.include "../../misc/bbdb/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
