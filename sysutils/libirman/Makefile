# $NetBSD: Makefile,v 1.6 2002/06/26 22:51:46 abs Exp $
#

DISTNAME=	libirman-0.4.1b
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.evation.com/libirman/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.evation.com/libirman/libirman.html
COMMENT=	Programming library for Irman - infrared control

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/irman.conf ${PKG_SYSCONFDIR}/irman.conf

post-build:
	    ${SED}  -e "s:/usr/local/etc:${PKG_SYSCONFDIR}:g" \
		    -e "s:/usr/local:${PREFIX}:g" \
		    -e 's/test_func/irman_func/g' \
		    -e 's/test_io/irman_func/g' \
		    -e 's/test_name/irman_func/g' \
			${WRKSRC}/README > ${WRKSRC}/libirman.README
	    ${SED}  -e 's:port /dev/ttyS1:port ${DEFAULT_SERIAL_DEVICE}:' \
			${WRKSRC}/irman.conf > ${WRKSRC}/irman.conf.patched
	    ${MV} ${WRKSRC}/irman.conf.patched ${WRKSRC}/irman.conf

post-install:
	    ${INSTALL_PROGRAM} ${WRKSRC}/test_func ${PREFIX}/bin/irman_func
	    ${INSTALL_PROGRAM} ${WRKSRC}/test_io ${PREFIX}/bin/irman_io
	    ${INSTALL_PROGRAM} ${WRKSRC}/test_name ${PREFIX}/bin/irman_name
	    ${INSTALL_DATA} ${WRKSRC}/libirman.README \
					${PREFIX}/share/doc/libirman.README

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
