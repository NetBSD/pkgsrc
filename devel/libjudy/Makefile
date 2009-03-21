# $NetBSD: Makefile,v 1.3 2009/03/21 16:07:02 darcy Exp $

DISTNAME=	Judy-1.0.4
PKGNAME=	libjudy-1.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=judy/}

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://judy.sourceforge.net/
COMMENT=	High-performance sparse dynamic array library

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

TEST_TARGET=		check

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
AUTO_MKDIRS=		yes
PKG_DESTDIR_SUPPORT=	user-destdir

post-install:
.for i in AUTHORS ChangeLog COPYING README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
