# $NetBSD: Makefile,v 1.1.1.1 2000/07/15 08:00:45 jlam Exp $

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
	${RM} -f ${PREFIX}/lib/libsigc.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sigc++
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/sigc++

.include "../../mk/bsd.pkg.mk"
