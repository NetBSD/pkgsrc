# $NetBSD: Makefile,v 1.2 2000/07/15 08:41:26 jlam Exp $

DISTNAME=		libsigc++-1.0.1
CATEGORIES=		devel
MASTER_SITES=		ftp://download.sourceforge.net/pub/sourceforge/libsigc/

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
