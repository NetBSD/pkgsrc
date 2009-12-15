# $NetBSD: Makefile,v 1.21 2009/12/15 18:59:54 bouyer Exp $
#

CATEGORIES=	net sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/nagiosplug/
COMMENT=	Nagios plugins

.include "../../net/nagios-plugins/Makefile.common"

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	perl:run

PKG_GROUPS+=	${NAGIOS_GROUP}

CONFIGURE_ARGS+= --without-pgsql --without-mysql \
		--without-smbclient-command --without-snmpget-command \
		--without-snmpgetnext-command --without-fping-command

SPECIAL_PERMS+=	${PREFIX}/libexec/nagios/check_icmp ${REAL_ROOT_USER} ${NAGIOS_GROUP} 4550

PLIST_VARS+=	linux
.if ${OPSYS} == "Linux"
PLIST.linux=	yes
.endif

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-df-command="/bin/df -Pklt nokernfs,procfs,fdesc"
.endif

# required to enable large file support on Solaris
.if ${OPSYS} == "SunOS"
CPPFLAGS_LFS!=		getconf LFS_CFLAGS
MAKE_ENV+=		CPPFLAGS_LFS=${CPPFLAGS_LFS:Q}
.endif
LIBS.SunOS+=	-lm

.if !exists(/usr/bin/ssh)
DEPENDS+=	{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/openssh
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
