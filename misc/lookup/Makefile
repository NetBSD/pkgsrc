# $NetBSD: Makefile,v 1.8 2003/08/09 11:14:08 seb Exp $
#

DISTNAME=	lookup-1.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lookup/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://lookup.sourceforge.net/
COMMENT=	Electric dictionary agent for Emacs

DEPENDS+=	${PKGNAME_PREFIX}apel>=10:../../devel/apel
DEPENDS+=	eblook>=1.3:../../textproc/eblook

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs20

GNU_CONFIGURE=	YES
MAKEFLAGS+=	lispdir=${EMACS_LISPPREFIX}/lookup

INFO_FILES=	lookup.info lookup-guide.info

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
