# $NetBSD: Makefile,v 1.1.1.1 2002/09/15 13:33:22 uebayasi Exp $
#

DISTNAME=	lookup-1.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lookup/}

MAINTAINER=	uebayasi@netbsd.org
HOMEPAGE=	http://lookup.sourceforge.net/
COMMENT=	electric dictionary agent for Emacs

DEPENDS=	apel>=10:../../devel/apel
DEPENDS=	eblook>=1.3:../../textproc/eblook

GNU_CONFIGURE=	YES
MAKEFLAGS+=	lispdir=${EMACS_LISPPREFIX}/lookup

INFO_FILES=	lookup.info

.include "../../mk/emacs.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
