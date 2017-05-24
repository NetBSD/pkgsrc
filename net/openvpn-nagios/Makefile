# $NetBSD: Makefile,v 1.8 2017/05/24 20:35:12 adam Exp $

.include "../../net/openvpn/Makefile.common"

DISTNAME=	openvpn-nagios-20130210
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${OPENVPN_DISTFILE}
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/openvpn-nagios/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/openvpn-nagios/
COMMENT=	OpenVPN certificate checks for Nagios
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
USE_TOOLS+=	install

MAKE_ENV+=	OPENVPN_PLUGINSDIR=${PREFIX}/${OPENVPN_PLUGINSDIR}
MAKE_ENV+=	OPENVPN_DISTNAME=${OPENVPN_DISTNAME}

PLIST_SUBST+=	OPENVPN_PLUGINSDIR=${OPENVPN_PLUGINSDIR}
MESSAGE_SUBST+=	OPENVPN_PLUGINSDIR=${PREFIX}/${OPENVPN_PLUGINSDIR}

DEPENDS+=	openvpn>=2.4.2:../../net/openvpn

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
