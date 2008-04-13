# $NetBSD: Makefile,v 1.16 2008/04/13 12:20:18 dillo Exp $
#

DISTNAME=	cftp-0.12
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://ftp.giga.or.at/pub/nih/cftp/ \
		ftp://ftp.giga.or.at/pub/nih/cftp/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://ftp.giga.or.at/pub/nih/cftp/
COMMENT=	Comfortable FTP, a full screen ftp client

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
INFO_FILES=	# PLIST

BUILD_DEFS+=	IPV6_READY

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cftp
	cd ${WRKSRC} && ${INSTALL_MAN} README bindings.desc \
		${DESTDIR}${PREFIX}/share/doc/cftp

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
