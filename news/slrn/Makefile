# $NetBSD: Makefile,v 1.10 2000/10/30 14:17:19 mjl Exp $
#

DISTNAME=		slrn-0.9.6.3
CATEGORIES=		news
MASTER_SITES=		ftp://space.mit.edu/pub/davis/slrn/ \
			ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/slrn/

MAINTAINER=		mjl@netbsd.org
HOMEPAGE=		http://space.mit.edu/%7Edavis/slrn.html

DEPENDS+=		libslang-*:../../devel/libslang

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-X

# the next is a workaround, as 1.3.2 install doesn't like -c and -d
# together
CONFIGURE_ENV+=		INSTALL=/usr/bin/install

.include "../../mk/bsd.pkg.mk"
