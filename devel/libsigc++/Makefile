# $NetBSD: Makefile,v 1.3 2000/11/11 17:49:24 tron Exp $

DISTNAME=		libsigc++-1.0.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libsigc/}

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://libsigc.sourceforge.net/

GNU_CONFIGURE=		# defined
CONFIGURE_ARG=		--disable-threads

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/scripts/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sigc++
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/sigc++

.include "../../mk/bsd.pkg.mk"
