# $NetBSD: Makefile,v 1.5 2002/11/14 23:47:33 jlam Exp $
#

DISTNAME=	ctags-5.2.3
PKGNAME=	ex${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctags/}

MAINTAINER=	seb@netbsd.org
HOMEPAGE=	http://ctags.sourceforge.net/
COMMENT=	Exuberant (feature-filled) tagfile generator for vi, emacs and clones

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-macro-patterns
CONFIGURE_ARGS+=	--with-readlib

CPPFLAGS+=		-DETAGS='\"exetags\"'

.include "../../mk/bsd.pkg.mk"
