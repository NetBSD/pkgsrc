# $NetBSD: Makefile,v 1.16 2007/11/12 15:29:49 uebayasi Exp $

DISTNAME=	tamago-4.0.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}tamago-20020909
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://www.m17n.org/pub/tamago/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.m17n.org/tamago/
COMMENT=	CJK characters inputting system for emacs + leim

GNU_CONFIGURE=	yes
# XXX please someone adjust paths and PLIST for XEmacs...
EMACS_VERSIONS_ACCEPTED= emacs22 emacs22nox emacs21 emacs21nox emacs20
EMACS_MODULES+=	leim

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs" && ${EMACS_VERSION_MAJOR} >= 21
PLIST_SUBST+=	HAVE_JISX0213=	# empty
.else
PLIST_SUBST+=	HAVE_JISX0213="@comment "
.endif

.include "../../mk/bsd.pkg.mk"
