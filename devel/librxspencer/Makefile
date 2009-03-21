# $NetBSD: Makefile,v 1.3 2009/03/21 16:07:03 darcy Exp $

DISTNAME=	rxspencer-alpha3.8.g4
PKGNAME=	librxspencer-3.8.4
CATEGORIES=	devel
MASTER_SITES=	http://arglist.com/regex/

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://arglist.com/regex/
COMMENT=	POSIX API regexp library by Henry Spencer

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-shared

TEST_TARGET=		check

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

AUTO_MKDIRS=		yes
PKG_DESTDIR_SUPPORT=	user-destdir

post-install:
	set -e; \
	for i in COPYRIGHT INSTALL README WHATSNEW; do \
		${INSTALL_DATA} ${WRKSRC}/"$${i}" ${DESTDIR}${DOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
