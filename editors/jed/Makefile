# $NetBSD: Makefile,v 1.13 2001/09/14 22:48:27 wiz Exp $
#

DISTNAME=		jed-B0.99-14
PKGNAME=		jed-0.99.14
CATEGORIES=		editors
MASTER_SITES=		ftp://space.mit.edu/pub/davis/jed/v0.99/ \
			ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/jed/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://space.mit.edu/%7Edavis/jed.html
COMMENT=		Text editor with many features, extensible through S-Lang functions

DEPENDS+=		libslang-*:../../devel/libslang

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-X

WRKSRC=			${WRKDIR}/jed-B0.99-14

.include "../../mk/bsd.pkg.mk"
