# $NetBSD: Makefile,v 1.8 2002/09/17 15:33:04 dillo Exp $
#

DISTNAME=	cftp-0.12
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

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
