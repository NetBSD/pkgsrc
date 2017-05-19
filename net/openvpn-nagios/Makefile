# $NetBSD: Makefile,v 1.7 2017/05/19 18:11:04 spz Exp $

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

MAKE_ENV+=	OPENVPN_PLUGINSDIR=${PREFIX:Q}/${OPENVPN_PLUGINSDIR:Q}
MAKE_ENV+=	OPENVPN_DISTNAME=${OPENVPN_DISTNAME:Q}

PLIST_SUBST+=	OPENVPN_PLUGINSDIR=${OPENVPN_PLUGINSDIR:Q}
MESSAGE_SUBST+=	OPENVPN_PLUGINSDIR=${PREFIX:Q}/${OPENVPN_PLUGINSDIR:Q}

DEPENDS+=	openvpn>=2.3.0<2.4:../../net/openvpn

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
