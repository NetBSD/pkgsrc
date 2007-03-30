# $NetBSD: Makefile,v 1.9 2007/03/30 05:52:37 grant Exp $
#

PKGREVISION=	2
CATEGORIES=	net sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/nagiosplug/
COMMENT=	Nagios plugins

.include "../../net/nagios-plugins/Makefile.common"

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	perl:run

CONFIGURE_ARGS+= --without-pgsql --without-mysql \
		--without-smbclient-command --without-snmpget-command \
		--without-snmpgetnext-command --without-fping-command

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-df-command="/bin/df -Pklt nokernfs,procfs,fdesc"
.endif

# required to enable large file support on Solaris
.if ${OPSYS} == "SunOS"
CPPFLAGS_LFS!=		getconf LFS_CFLAGS
MAKE_ENV+=		CPPFLAGS_LFS=${CPPFLAGS_LFS:Q}
.endif

.if !exists(/usr/bin/ssh)
DEPENDS+=	{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/openssh
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
