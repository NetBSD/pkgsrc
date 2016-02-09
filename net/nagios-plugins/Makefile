# $NetBSD: Makefile,v 1.41 2016/02/09 10:13:17 bouyer Exp $
#

PKGREVISION=	1
CATEGORIES=	net sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/nagiosplug/
COMMENT=	Nagios plugins
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../net/nagios-plugins/Makefile.common"

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	msgfmt msgmerge intltool perl:run xgettext

PKG_GROUPS+=	${NAGIOS_GROUP}
BUILD_DEFS+=	${NAGIOS_GROUP}

CONFIGURE_ARGS+= --without-pgsql --without-mysql \
		--without-smbclient-command --without-snmpget-command \
		--without-snmpgetnext-command --without-fping-command \
		--without-apt-get-command

SPECIAL_PERMS+=	${PREFIX}/libexec/nagios/check_icmp ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/libexec/nagios/check_dhcp ${SETUID_ROOT_PERMS}

PLIST_VARS+=	linux sunos NetBSD
.if ${OPSYS} == "Linux"
PLIST.linux=	yes
.elif ${OPSYS} == "SunOS"
PLIST.sunos=	yes
.elif ${OPSYS} == "NetBSD"
PLIST.NetBSD=	yes
.endif

.if ${OPSYS} == "NetBSD"
SPECIAL_PERMS+=	${PREFIX}/libexec/nagios/check_ide_smart \
		${REAL_ROOT_USER} ${NAGIOS_GROUP} 4551
.endif

# required to enable large file support on Solaris
.if ${OPSYS} == "SunOS"
CPPFLAGS_LFS!=		getconf LFS_CFLAGS
MAKE_ENV+=		CPPFLAGS_LFS=${CPPFLAGS_LFS:Q}
.endif
LIBS.SunOS+=	-lm

#DEPENDS+=	nagios-base-*:../../net/nagios-base

.if !exists(/usr/bin/ssh)
DEPENDS+=	{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/openssh
.endif

.if (!exists(/usr/bin/dig) && !exists(/usr/sbin/dig)) || \
    (!exists(/usr/bin/nslookup) && !exists(/usr/sbin/nslookup))
DEPENDS+=	bind-[0-9]*:../../net/bind910
.endif

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/libexec/nagios/utils.pm

.include "../../mk/pthread.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
