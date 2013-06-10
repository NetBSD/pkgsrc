# $NetBSD: Makefile,v 1.27 2013/06/10 21:51:04 jnemeth Exp $

DISTNAME=	tamago-4.0.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}tamago-20020909
PKGREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	http://unit.aist.go.jp/itri/itri-gist/ftp.m17n.org/pub/tamago/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.m17n.org/tamago/
COMMENT=	CJK characters inputting system for emacs + leim

GNU_CONFIGURE=	yes
MAKE_FLAGS+=	prefix=${DESTDIR:Q}${PREFIX}
# XXX please someone adjust paths and PLIST for XEmacs...
EMACS_VERSIONS_ACCEPTED=	emacs24 emacs24nox \
				emacs23 emacs23nox \
				emacs22 emacs22nox \
				emacs21 emacs21nox \
				emacs20
EMACS_MODULES+=	leim

.include "../../editors/emacs/modules.mk"

PLIST_VARS+=	jisx0213

.if ${EMACS_FLAVOR} == "emacs" && ${EMACS_VERSION_MAJOR} >= 21
PLIST.jisx0213=	yes
.endif

.include "../../mk/bsd.pkg.mk"
