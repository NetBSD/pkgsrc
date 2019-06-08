# $NetBSD: Makefile,v 1.29 2019/06/08 10:40:58 rillig Exp $

DISTNAME=	tamago-4.0.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}tamago-20020909
PKGREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	http://unit.aist.go.jp/itri/itri-gist/ftp.m17n.org/pub/tamago/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.m17n.org/tamago/
COMMENT=	CJK characters inputting system for emacs + leim

GNU_CONFIGURE=	yes
MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
# XXX please someone adjust paths and PLIST for XEmacs...
EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20
EMACS_MODULES+=	leim

.include "../../editors/emacs/modules.mk"

PLIST_VARS+=	jisx0213

.if ${EMACS_FLAVOR} == "emacs" && ${EMACS_VERSION_MAJOR} >= 21
PLIST.jisx0213=	yes
.endif

.include "../../mk/bsd.pkg.mk"
