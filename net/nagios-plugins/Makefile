# $NetBSD: Makefile,v 1.27 2012/05/24 15:20:25 marino Exp $
#

PKGREVISION=	2
CATEGORIES=	net sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/nagiosplug/
COMMENT=	Nagios plugins
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	destdir

.include "../../net/nagios-plugins/Makefile.common"

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	perl:run

PKG_GROUPS+=	${NAGIOS_GROUP}
BUILD_DEFS+=	${NAGIOS_GROUP}

CONFIGURE_ARGS+= --without-pgsql --without-mysql \
		--without-smbclient-command --without-snmpget-command \
		--without-snmpgetnext-command --without-fping-command

SPECIAL_PERMS+=	${PREFIX}/libexec/nagios/check_icmp ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/libexec/nagios/check_dhcp ${SETUID_ROOT_PERMS}

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

DEPENDS+=	nagios-base-*:../../net/nagios-base

.if !exists(/usr/bin/ssh)
DEPENDS+=	{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/openssh
.endif

.if !exists(/usr/bin/dig) || !exists(/usr/bin/nslookup)
DEPENDS+=	bind-[0-9]*:../../net/bind96
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
