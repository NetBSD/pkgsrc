# $NetBSD: Makefile,v 1.3 2000/12/15 01:58:57 wiz Exp $
#

DISTNAME=	cftp-0.10
CATEGORIES=	net
MASTER_SITES=	ftp://sunsite.csd.smc.univie.ac.at/pub/nih/cftp/ \
		ftp://ftp.giga.or.at/pub/nih/cftp/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://sunsite.csd.smc.univie.ac.at/pub/nih/cftp/

GNU_CONFIGURE=	YES
INFO_FILES=	cftp.info

BUILD_DEFS+=	USE_INET6

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cftp
	cd ${WRKSRC} && ${INSTALL_MAN} README bindings.desc \
		${PREFIX}/share/doc/cftp

.include "../../mk/bsd.pkg.mk"
