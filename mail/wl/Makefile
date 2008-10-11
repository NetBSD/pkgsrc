# $NetBSD: Makefile,v 1.38 2008/10/11 09:31:57 uebayasi Exp $

DISTNAME=	wl-2.14.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.gohome.org/wl/stable/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.gohome.org/wl/
COMMENT=	Mail/news management system with IMAP4rev1 support for Emacs

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	all info
INSTALL_TARGET=	install install-info
MAKE_FLAGS+=	INFODIR=${DESTDIR:Q}${EMACS_INFOPREFIX:Q}
MAKE_FLAGS+=	LISPDIR=${DESTDIR:Q}${EMACS_LISPPREFIX:Q}
MAKE_FLAGS+=	EMACS=${EMACS_FLAVOR:Q}
MAKE_FLAGS+=	PIXMAPDIR=${DESTDIR:Q}${PREFIX:Q}/share/wl
INFO_FILES=	# PLIST

DOCDIR=			${PREFIX}/share/doc/wl
EXAMPLESDIR=		${PREFIX}/share/examples/wl
INSTALLATION_DIRS=	${DOCDIR}/en ${DOCDIR}/ja \
			${EXAMPLESDIR}/en ${EXAMPLESDIR}/ja \
			${EMACS_INFOPREFIX}

post-install:
	@set -e; \
	for f in BUGS NEWS README; do \
		${INSTALL_DATA} ${WRKSRC:Q}/"$$f" ${DESTDIR:Q}${DOCDIR:Q}/en; \
		${INSTALL_DATA} ${WRKSRC:Q}/"$$f".ja ${DESTDIR:Q}${DOCDIR:Q}/ja; \
	done
	${INSTALL_DATA} ${WRKSRC:Q}/samples/en/dot.* ${DESTDIR:Q}${EXAMPLESDIR:Q}/en
	${INSTALL_DATA} ${WRKSRC:Q}/samples/ja/dot.* ${DESTDIR:Q}${EXAMPLESDIR:Q}/ja

.include "../../editors/emacs/modules.mk"

.include "options.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../devel/semi/buildlink3.mk"
.include "../../misc/bbdb/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
