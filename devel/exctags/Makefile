# $NetBSD: Makefile,v 1.3 2002/01/23 11:48:29 seb Exp $
#

DISTNAME=	ctags-5.2
PKGNAME=	ex${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctags/}

MAINTAINER=	seb@netbsd.org
HOMEPAGE=	http://ctags.sourceforge.net/
COMMENT=	Exuberant (feature-filled) tagfile generator for vi, emacs and clones

GNU_CONFIGURE=		yes
USE_BUILDLINK_ONLY=	# defined
CONFIGURE_ARGS+=	--enable-macro-patterns
CONFIGURE_ARGS+=	--with-readlib

CPPFLAGS+=		-DETAGS='\"exetags\"'

.include "../../mk/bsd.pkg.mk"
