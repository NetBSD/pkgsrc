# $NetBSD: Makefile,v 1.7 2003/04/22 16:16:07 taca Exp $

DISTNAME=	tamago-4.0.6
PKGNAME=	tamago-20020909
CATEGORIES=	editors
MASTER_SITES=	ftp://www.m17n.org/pub/tamago/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.m17n.org/tamago/
COMMENT=	CJK characters inputting system for emacs + leim

GNU_CONFIGURE=	yes
# XXX please someone adjust paths and PLIST for XEmacs...
EMACS_VERSIONS_ACCEPTED= emacs21 emacs20
EMACS_USE_LEIM=	# defined

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
