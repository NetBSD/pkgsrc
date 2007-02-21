# $NetBSD: Makefile,v 1.1.1.1 2007/02/21 21:06:12 minskim Exp $

DISTNAME=	rxspencer-alpha3.8.g3
PKGNAME=	librxspencer-3.8.3
CATEGORIES=	devel
MASTER_SITES=	http://arglist.com/regex/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://arglist.com/regex/
COMMENT=	POSIX API regexp library by Henry Spencer

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-shared

TEST_TARGET=		check

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	set -e; \
	for i in COPYRIGHT INSTALL README WHATSNEW; do \
		${INSTALL_DATA} ${WRKSRC}/"$${i}" ${DOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
