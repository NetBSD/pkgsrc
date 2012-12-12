# $NetBSD: Makefile,v 1.20 2012/12/12 10:44:10 wiz Exp $
#

DISTNAME=	cftp-0.12
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://ftp.giga.or.at/pub/nih/cftp/ \
		ftp://ftp.giga.or.at/pub/nih/cftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ftp.giga.or.at/pub/nih/cftp/
COMMENT=	Comfortable FTP, a full screen ftp client

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
