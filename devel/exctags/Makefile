# $NetBSD: Makefile,v 1.2 2001/11/13 15:23:23 seb Exp $
#

DISTNAME=	ctags-5.1
PKGNAME=	ex${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctags/}

MAINTAINER=	seb@pbox.org
HOMEPAGE=	http://ctags.sourceforge.net/
COMMENT=	Exuberant (feature-filled) tagfile generator for vi, emacs and clones

GNU_CONFIGURE=		yes
USE_BUILDLINK_ONLY=	# defined
CONFIGURE_ARGS+=	--enable-macro-patterns
CONFIGURE_ARGS+=	--with-readlib

CPPFLAGS+=		-DETAGS='\"exetags\"'

.include "../../mk/bsd.pkg.mk"
