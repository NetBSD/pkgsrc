# $NetBSD: Makefile,v 1.11 2001/02/17 17:54:51 wiz Exp $
#

DISTNAME=		slrn-0.9.6.3
CATEGORIES=		news
MASTER_SITES=		ftp://space.mit.edu/pub/davis/slrn/ \
			ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/slrn/

MAINTAINER=		mjl@netbsd.org
HOMEPAGE=		http://space.mit.edu/%7Edavis/slrn.html
COMMENT=		Powerful threaded newsreader, that is highly customizable

DEPENDS+=		libslang-*:../../devel/libslang

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-X

# the next is a workaround, as 1.3.2 install doesn't like -c and -d
# together
CONFIGURE_ENV+=		INSTALL=/usr/bin/install

.include "../../mk/bsd.pkg.mk"
