# $NetBSD: Makefile,v 1.15 2001/05/06 09:39:08 wiz Exp $
#

DISTNAME=		slrn-0.9.7.0a
PKGNAME=		slrn-0.9.7.0.1
CATEGORIES=		news
MASTER_SITES=		ftp://slrn.sourceforge.net/pub/slrn/ \
			ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/slrn/ \
			ftp://ftp.fu-berlin.de/pub/unix/news/slrn/ \
			ftp://ftp.ntua.gr/pub/lang/slang/ \
			ftp://ftp.plig.org/pub/slrn/

MAINTAINER=		mjl@netbsd.org
HOMEPAGE=		http://slrn.sourceforge.net/
COMMENT=		Powerful threaded newsreader, that is highly customizable

DEPENDS+=		libslang-*:../../devel/libslang

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-X --disable-inews \
			--disable-gen-mid --with-libdir=${PREFIX}/lib/slrn

# the next is a workaround, as 1.3.2 install doesn't like -c and -d
# together
CONFIGURE_ENV+=		INSTALL=/usr/bin/install

post-build:
	cd ${WRKSRC} && make slrnpull

.include "../../mk/bsd.pkg.mk"
