# $NetBSD: Makefile,v 1.3 2017/08/14 15:24:42 jlam Exp $
#

PKGNAME=	nagios-plugin-milter-${DISTNAME:C/.*-//}
PKGREVISION=	1
DISTNAME=	check_milter-0.2
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/nagios-local/
COMMENT=	Milter monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+= libexec/nagios

BUILD_DEFS+=		NAGIOS_GROUP
PKG_GROUPS_VARS=	NAGIOS_GROUP
PKG_GROUPS=		${NAGIOS_GROUP}

# The default `smmsp' username and group match the ones hardcoded
# into mail/sendmail/Makefile.
#
SMMSP_USER?=		smmsp
BUILD_DEFS+=		SMMSP_USER
PKG_GROUPS_VARS=	SMMSP_USER
PKG_USERS_VARS=		SMMSP_USER
PKG_GROUPS=		${SMMSP_USER}
PKG_USERS=		${SMMSP_USER}:${SMMSP_USER}
PKG_GECOS.${SMMSP_USER}=Sendmail Message Submission Program

SPECIAL_PERMS+= ${PREFIX}/libexec/nagios/check_milter \
		${SMMSP_USER} ${NAGIOS_GROUP} 4554

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_milter \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
