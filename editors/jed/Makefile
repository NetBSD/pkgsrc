# $NetBSD: Makefile,v 1.9 2000/01/01 17:11:28 mjl Exp $
#

DISTNAME=		jed0.98-7
PKGNAME=		jed-0.98-7
CATEGORIES=		editors
MASTER_SITES=		ftp://space.mit.edu/pub/davis/jed/v0.98/ \
			ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/jed/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://space.mit.edu/%7Edavis/jed.html

DEPENDS+=		libslang-*:../../devel/libslang

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-X

WRKSRC=			${WRKDIR}/jed

.include "../../mk/bsd.pkg.mk"
