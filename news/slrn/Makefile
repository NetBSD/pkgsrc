# $NetBSD: Makefile,v 1.7 1999/07/22 07:10:48 mycroft Exp $
#

DISTNAME=		slrn-0.9.5.6
CATEGORIES=		news
MASTER_SITES=		ftp://space.mit.edu/pub/davis/slrn/ \
			ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/slrn/

MAINTAINER=		mjl@netbsd.org
HOMEPAGE=		http://space.mit.edu/%7Edavis/slrn.html

DEPENDS+=		libslang-1.3.8:../../devel/libslang

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-X

# the next is a workaround, as 1.3.2 install doesn't like -c and -d
# together
CONFIGURE_ENV+=		INSTALL=/usr/bin/install

.include "../../mk/bsd.pkg.mk"
