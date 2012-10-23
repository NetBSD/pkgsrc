# $NetBSD: Makefile,v 1.16 2012/10/23 19:51:10 asau Exp $
#

DISTNAME=	libirman-0.4.1c
CATEGORIES=	sysutils
MASTER_SITES=	http://libirman.googlecode.com/files/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libirman/
COMMENT=	Programming library for Irman - infrared control

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/irman.conf ${PKG_SYSCONFDIR}/irman.conf

INSTALLATION_DIRS=	share/doc share/examples

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

.include "../../mk/bsd.pkg.mk"
