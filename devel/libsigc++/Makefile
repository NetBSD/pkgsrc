# $NetBSD: Makefile,v 1.6 2001/10/21 12:46:24 wiz Exp $

DISTNAME=		libsigc++-1.0.3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libsigc/}

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://libsigc.sourceforge.net/
COMMENT=		libsigc++ is provides a callback system for C++ programs

GNU_CONFIGURE=		YES
CONFIGURE_ARG=		--disable-threads

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/scripts/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sigc++
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/sigc++

.include "../../mk/bsd.pkg.mk"
