# $NetBSD: Makefile,v 1.1.1.1 1998/10/31 21:09:13 hwr Exp $

DISTNAME=			slrn0.9.5.3
CATEGORIES=			news
MASTER_SITES=			ftp://space.mit.edu/pub/davis/slrn/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/slrn/

MAINTAINER=			packages@netbsd.org
HOMEPAGE=			http://space.mit.edu/%7Edavis/slrn.html

BUILD_DEPENDS+=			libslang-1.2.2:../../devel/libslang
DEPENDS+=			libslang-1.2.2:../../devel/libslang


GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-X --prefix=${PREFIX} 

# the next is a workaround, as 1.3.2 install doesn't like -c and -d
# together
CONFIGURE_ENV+=		INSTALL=/usr/bin/install

WRKSRC=				${WRKDIR}/slrn

.include "../../mk/bsd.pkg.mk"


