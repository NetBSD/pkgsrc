# $NetBSD: Makefile,v 1.4 2001/02/16 14:38:38 wiz Exp $

DISTNAME=		libsigc++-1.0.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libsigc/}

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://libsigc.sourceforge.net/
COMMENT=		libsigc++ is provides a callback system for C++ programs

GNU_CONFIGURE=		# defined
CONFIGURE_ARG=		--disable-threads

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/scripts/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sigc++
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/sigc++

.include "../../mk/bsd.pkg.mk"
