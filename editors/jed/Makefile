# $NetBSD: Makefile,v 1.14 2001/09/27 23:18:00 jlam Exp $
#

DISTNAME=		jed-B0.99-14
PKGNAME=		jed-0.99.14
CATEGORIES=		editors
MASTER_SITES=		ftp://space.mit.edu/pub/davis/jed/v0.99/ \
			ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/jed/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://space.mit.edu/%7Edavis/jed.html
COMMENT=		Text editor with many features, extensible through S-Lang functions

DEPENDS+=		libslang-[0-9]*:../../devel/libslang

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-X

WRKSRC=			${WRKDIR}/jed-B0.99-14

.include "../../mk/bsd.pkg.mk"
