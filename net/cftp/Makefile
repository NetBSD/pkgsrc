# $NetBSD: Makefile,v 1.7 2002/02/18 15:14:36 seb Exp $
#

DISTNAME=	cftp-0.11
PKGREVISION=	1
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
