# $NetBSD: Makefile,v 1.4 2003/01/19 08:45:38 salo Exp $
#

DISTNAME=	pnm2ppa-1.04
PKGREVISION=	1
CATEGORIES=	print converters graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pnm2ppa/}

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://pnm2ppa.sourceforge.net/
COMMENT=	filter to convert PNM file to PPA used by some HP DJ printer

CONF_FILES+=	${PREFIX}/share/examples/pnm2ppa/pnm2ppa.conf.default	\
		${PKG_SYSCONFDIR}/pnm2ppa.conf

post-build:
	for f in				\
	${WRKSRC}/docs/en/CALIBRATION.txt	\
	${WRKSRC}/docs/en/COLOR.txt		\
	${WRKSRC}/docs/en/pnm2ppa.1 ;		\
	do					\
		${CP} $$f $$f.orig ;		\
		${SED} 's|/etc/pnm2ppa|${PKG_SYSCONFDIR}/pnm2ppa|g'	\
			$$f.orig > $$f ;	\
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pnm2ppa
	cd ${WRKSRC} &&	\
	${INSTALL_DATA} docs/en/CALIBRATION.txt	docs/en/COLOR.txt	\
		${PREFIX}/share/doc/pnm2ppa

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
