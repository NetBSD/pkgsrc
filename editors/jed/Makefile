# $NetBSD: Makefile,v 1.1.1.1 1998/10/31 23:16:12 hwr Exp $

DISTNAME=			jed0.98-7
CATEGORIES=			editors
MASTER_SITES=			ftp://space.mit.edu/pub/davis/jed/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/jed/

MAINTAINER=			packages@netbsd.org
HOMEPAGE=			http://space.mit.edu/%7Edavis/jed.html

BUILD_DEPENDS+=			libslang-1.2.2:../../devel/libslang
DEPENDS+=			libslang-1.2.2:../../devel/libslang


CONFIGURE_ARGS+=	--without-X --prefix=${PREFIX} 
GNU_CONFIGURE=		yes

WRKSRC=				${WRKDIR}/jed

.include "../../mk/bsd.pkg.mk"


