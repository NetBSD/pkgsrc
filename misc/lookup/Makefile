# $NetBSD: Makefile,v 1.4 2002/11/14 03:46:43 wiz Exp $
#

DISTNAME=	lookup-1.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lookup/}

MAINTAINER=	uebayasi@netbsd.org
HOMEPAGE=	http://lookup.sourceforge.net/
COMMENT=	electric dictionary agent for Emacs

DEPENDS+=	${PKGNAME_PREFIX}apel>=10:../../devel/apel
DEPENDS+=	eblook>=1.3:../../textproc/eblook

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs20

GNU_CONFIGURE=	YES
MAKEFLAGS+=	lispdir=${EMACS_LISPPREFIX}/lookup

INFO_FILES=	lookup.info

.include "../../mk/emacs.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
