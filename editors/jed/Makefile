# $NetBSD: Makefile,v 1.5 1999/06/22 07:34:15 tron Exp $
#

DISTNAME=		jed0.98-7
PKGNAME=		jed-0.98-7
CATEGORIES=		editors
MASTER_SITES=		ftp://space.mit.edu/pub/davis/jed/v0.98/ \
			ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/jed/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://space.mit.edu/%7Edavis/jed.html

DEPENDS+=		libslang-1.3.7:../../devel/libslang

CONFIGURE_ARGS+=	--without-X --prefix=${PREFIX}
GNU_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/jed

.include "../../mk/bsd.pkg.mk"
