# $NetBSD: Makefile,v 1.12 2001/02/16 14:40:50 wiz Exp $
#

DISTNAME=		jed0.98-7
PKGNAME=		jed-0.98.7
CATEGORIES=		editors
MASTER_SITES=		ftp://space.mit.edu/pub/davis/jed/v0.98/ \
			ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/jed/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://space.mit.edu/%7Edavis/jed.html
COMMENT=		Texteditor with many features, extensible through S-Lang functions

DEPENDS+=		libslang-*:../../devel/libslang

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-X

WRKSRC=			${WRKDIR}/jed

.include "../../mk/bsd.pkg.mk"
