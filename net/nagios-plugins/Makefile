# $NetBSD: Makefile,v 1.3 2006/08/17 14:20:14 taca Exp $
#

CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nagiosplug/}

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=       http://sourceforge.net/projects/nagiosplug/
COMMENT=	Nagios plugins

.include "../../net/nagios-plugins/Makefile.common"

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+= --without-pgsql --without-mysql \
		--without-smbclient-command --without-snmpget-command \
		--without-snmpgetnext-command --without-fping-command

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=      --with-df-command="/bin/df -Pklt nokernfs,procfs,fdesc"
.endif

DEPENDS+=	nagios-base>=2.0:../../net/nagios-base

.if !exists(/usr/bin/ssh)
DEPENDS+=	{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/openssh
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
