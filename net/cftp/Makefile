# $NetBSD: Makefile,v 1.5 2001/09/11 23:07:57 dillo Exp $
#

DISTNAME=	cftp-0.11
CATEGORIES=	net
MASTER_SITES=	ftp://sunsite.csd.smc.univie.ac.at/pub/nih/cftp/ \
		ftp://ftp.giga.or.at/pub/nih/cftp/

MAINTAINER=	dillo@netbsd.org
HOMEPAGE=	http://sunsite.csd.smc.univie.ac.at/pub/nih/cftp/
COMMENT=	Comfortable FTP, a full screen ftp client

GNU_CONFIGURE=	YES
INFO_FILES=	cftp.info

BUILD_DEFS+=	USE_INET6

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cftp
	cd ${WRKSRC} && ${INSTALL_MAN} README bindings.desc \
		${PREFIX}/share/doc/cftp

.include "../../mk/bsd.pkg.mk"
