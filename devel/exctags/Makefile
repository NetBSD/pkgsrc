# $NetBSD: Makefile,v 1.4 2002/03/06 16:45:01 seb Exp $
#

DISTNAME=	ctags-5.2.3
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
