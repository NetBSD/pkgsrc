# $NetBSD: Makefile,v 1.8 2017/05/19 18:11:04 spz Exp $

.include "../../net/openvpn/Makefile.common"

DISTNAME=	openvpn-acct-wtmpx-20130210
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${OPENVPN_DISTFILE}
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/openvpn-acct-wtmpx/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/openvpn-acct-wtmpx/
COMMENT=	Log OpenVPN logins and logouts to wtmpx
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
USE_TOOLS+=	install

MAKE_ENV+=	OPENVPN_PLUGINSDIR=${PREFIX:Q}/${OPENVPN_PLUGINSDIR:Q}
MAKE_ENV+=	OPENVPN_DISTNAME=${OPENVPN_DISTNAME:Q}

PLIST_SUBST+=	OPENVPN_PLUGINSDIR=${OPENVPN_PLUGINSDIR:Q}
MESSAGE_SUBST+=	OPENVPN_PLUGINSDIR=${PREFIX:Q}/${OPENVPN_PLUGINSDIR:Q}

SPECIAL_PERMS+=	bin/logwtmpx ${SETUID_ROOT_PERMS}

.include "../../mk/bsd.pkg.mk"
