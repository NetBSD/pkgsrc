# $NetBSD: Makefile,v 1.7 2026/08/04 20:29:11 wiz Exp $
#

DISTNAME=	check_milter-0.2
PKGNAME=	nagios-plugin-milter-${DISTNAME:C/.*-//}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/nagios-local/
COMMENT=	Milter monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	libexec/nagios

BUILD_DEFS+=		NAGIOS_GROUP
PKG_GROUPS_VARS=	NAGIOS_GROUP
PKG_GROUPS=		${NAGIOS_GROUP}

# The default `smmsp' username and group match the ones hardcoded
# into mail/sendmail/Makefile.
#
SMMSP_USER?=			smmsp
BUILD_DEFS+=			SMMSP_USER
PKG_GROUPS_VARS+=		SMMSP_USER
PKG_USERS_VARS=			SMMSP_USER
PKG_GROUPS+=			${SMMSP_USER}
PKG_USERS=			${SMMSP_USER}:${SMMSP_USER}
PKG_GECOS.${SMMSP_USER}=	Sendmail Message Submission Program

SPECIAL_PERMS+=	${PREFIX}/libexec/nagios/check_milter \
		${SMMSP_USER} ${NAGIOS_GROUP} 4554

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_milter \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
