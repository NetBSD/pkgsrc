# $NetBSD: Makefile,v 1.3 2021/06/29 00:08:50 tnn Exp $
#

DISTNAME=	nagios-4.0.8
PKGREVISION=	1
CATEGORIES=	meta-pkgs net
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta package for Nagios
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND modified-bsd

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	nagios-base>=4.0.8:../../net/nagios-base
DEPENDS+=	nagios-plugins>=2.0.3:../../net/nagios-plugins
DEPENDS+=	nagios-plugin-dnsrbl>=0.2:../../net/nagios-plugin-dnsrbl
DEPENDS+=	nagios-plugin-dotpid>=0.3:../../net/nagios-plugin-dotpid
DEPENDS+=	nagios-plugin-dumpdates>=0.2:../../net/nagios-plugin-dumpdates
DEPENDS+=	nagios-plugin-fstab>=0.2:../../net/nagios-plugin-fstab
DEPENDS+=	nagios-plugin-ldap>=2.0.3:../../net/nagios-plugin-ldap
DEPENDS+=	nagios-plugin-milter>=0.1:../../net/nagios-plugin-milter
DEPENDS+=	nagios-plugin-mysql>=2.0.3:../../net/nagios-plugin-mysql
DEPENDS+=	nagios-plugin-pgsql>=2.0.3:../../net/nagios-plugin-pgsql
DEPENDS+=	nagios-plugin-radius>=2.0.3:../../net/nagios-plugin-radius
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
DEPENDS+=	nagios-plugin-raidctl>=0.1:../../net/nagios-plugin-raidctl
.endif
DEPENDS+=	nagios-plugin-spamd>=1.6.0:../../net/nagios-plugin-spamd
DEPENDS+=	nagios-plugin-snmp>=2.0.3:../../net/nagios-plugin-snmp
DEPENDS+=	nagios-plugin-syncrepl>=0.1:../../net/nagios-plugin-syncrepl

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
