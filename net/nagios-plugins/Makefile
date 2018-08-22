# $NetBSD: Makefile,v 1.47 2018/08/22 09:45:55 wiz Exp $
#

PKGREVISION=	1
CATEGORIES=	net sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/nagiosplug/
COMMENT=	Nagios plugins
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../net/nagios-plugins/Makefile.common"

USE_TOOLS+=	msgfmt msgmerge intltool perl:run xgettext

PKG_GROUPS+=	${NAGIOS_GROUP}

CONFIGURE_ARGS+= --without-pgsql --without-mysql \
		--without-smbclient-command --without-snmpget-command \
		--without-snmpgetnext-command --without-fping-command \
		--without-apt-get-command

SPECIAL_PERMS+=	${PREFIX}/libexec/nagios/check_icmp ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/libexec/nagios/check_dhcp ${SETUID_ROOT_PERMS}

PLIST_VARS+=	ide swap

.if ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
PLIST.ide=	yes
.endif

.if ${OPSYS} != "Darwin"
PLIST.swap=	yes
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

.if ${OPSYS} == "NetBSD"
PING_CMD=	/sbin/ping -n -w %d -c %d %s
# The configure logic can't deal with IPv4 ping accepting a timeout (-w option) but IPv6 ping lacking it.
# So stuff the timeout into the -p (pad) option of ping6.
PING6_CMD=	/sbin/ping6 -n -p %d -c %d %s
.else
PING_CMD=	# empty
PING6_CMD=	# empty
.endif

.if !empty(PING_CMD)
CONFIGURE_ARGS+=	--with-ping-command="${PING_CMD}"
.endif
.if !empty(PING6_CMD)
CONFIGURE_ARGS+=	--with-ping6-command="${PING6_CMD}"
.endif

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/libexec/nagios/utils.pm

.include "../../mk/pthread.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
