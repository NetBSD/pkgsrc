# $NetBSD: Makefile,v 1.2 2011/11/23 23:31:22 joerg Exp $
#

DISTNAME=	openvpn-acct-wtmpx-20091110
PKGREVISION=	1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} openvpn-2.1_rc20.tar.gz
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/openvpn-acct-wtmpx/
SITES.openvpn-2.1_rc20.tar.gz=	http://openvpn.net/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/openvpn-acct-wtmpx/
COMMENT=	Log OpenVPN logins and logouts to wtmpx

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
USE_TOOLS+=	install

WRKSRC=	${WRKDIR}/openvpn-acct-wtmpx

SPECIAL_PERMS+=	bin/logwtmpx ${SETUID_ROOT_PERMS}

.include "../../mk/bsd.pkg.mk"
