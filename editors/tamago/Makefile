# $NetBSD: Makefile,v 1.9 2004/05/08 13:35:20 uebayasi Exp $

DISTNAME=	tamago-4.0.6
PKGNAME=	tamago-20020909
CATEGORIES=	editors
MASTER_SITES=	ftp://www.m17n.org/pub/tamago/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.m17n.org/tamago/
COMMENT=	CJK characters inputting system for emacs + leim

GNU_CONFIGURE=	yes
# XXX please someone adjust paths and PLIST for XEmacs...
EMACS_VERSIONS_ACCEPTED= emacs21 emacs21nox emacs20
EMACS_USE_LEIM=	# defined

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
