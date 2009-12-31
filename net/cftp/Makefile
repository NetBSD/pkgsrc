# $NetBSD: Makefile,v 1.18 2009/12/31 08:37:31 wiz Exp $
#

DISTNAME=	cftp-0.12
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://ftp.giga.or.at/pub/nih/cftp/ \
		ftp://ftp.giga.or.at/pub/nih/cftp/

OWNER=		dillo@NetBSD.org
HOMEPAGE=	http://ftp.giga.or.at/pub/nih/cftp/
COMMENT=	Comfortable FTP, a full screen ftp client

PKG_DESTDIR_SUPPORT=	user-destdir

# bin/cftp
CONFLICTS=	py[0-9]*-twisted-[0-9]*

GNU_CONFIGURE=	YES
INFO_FILES=	YES

BUILD_DEFS+=	IPV6_READY

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cftp
	cd ${WRKSRC} && ${INSTALL_MAN} README bindings.desc \
		${DESTDIR}${PREFIX}/share/doc/cftp

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
