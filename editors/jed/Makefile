# $NetBSD: Makefile,v 1.7 1999/07/22 07:10:47 mycroft Exp $
#

DISTNAME=		jed0.98-7
PKGNAME=		jed-0.98-7
CATEGORIES=		editors
MASTER_SITES=		ftp://space.mit.edu/pub/davis/jed/v0.98/ \
			ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/jed/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://space.mit.edu/%7Edavis/jed.html

DEPENDS+=		libslang-1.3.8:../../devel/libslang

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-X

WRKSRC=			${WRKDIR}/jed

.include "../../mk/bsd.pkg.mk"
