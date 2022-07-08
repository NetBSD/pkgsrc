# $NetBSD: Makefile,v 1.20 2022/07/08 22:10:29 wiz Exp $

DISTNAME=	fail2ban-0.11.2
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=fail2ban/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	http://www.fail2ban.org/
COMMENT=	Scans log files and bans IP that makes too many password failures
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

BUILD_DEPENDS+=	${PYPKGPREFIX}-numpydoc-[0-9]*:../../textproc/py-numpydoc
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_TOOLS+=	make:build

USE_LANGUAGES=		# none
EGDIR=			${PREFIX}/share/examples/fail2ban
PKG_SYSCONFSUBDIR=	fail2ban
DOCDIR=			${PREFIX}/share/doc/fail2ban
OWN_DIRS=		${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/action.d/ ${PKG_SYSCONFDIR}/filter.d/ \
			${VARBASE}/run/fail2ban ${VARBASE}/db/fail2ban
INSTALLATION_DIRS+=	${PKGMANDIR}/man1/ ${PKGMANDIR}/man5/ ${EGDIR} ${EGDIR}/action.d/ ${EGDIR}/filter.d/ ${EGDIR}/filter.d/ignorecommands/ \
			${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/action.d/ ${PKG_SYSCONFDIR}/filter.d/ ${PKG_SYSCONFDIR}/filter.d/ignorecommands/ \
			${DOCDIR}

.for config in paths-arch.conf paths-common.conf paths-debian.conf paths-fedora.conf paths-freebsd.conf paths-opensuse.conf paths-osx.conf paths-netbsd.conf fail2ban.conf jail.conf paths-pkgsrc.conf
CONF_FILES+=		${EGDIR}/${config} ${PKG_SYSCONFDIR}/${config}
.endfor

.for action in abuseipdb.conf apf.conf badips.conf badips.py blocklist_de.conf bsd-ipfw.conf cloudflare.conf complain.conf dshield.conf dummy.conf firewallcmd-allports.conf firewallcmd-common.conf firewallcmd-ipset.conf firewallcmd-multiport.conf firewallcmd-new.conf firewallcmd-rich-logging.conf firewallcmd-rich-rules.conf helpers-common.conf hostsdeny.conf ipfilter.conf ipfw.conf iptables-allports.conf iptables-common.conf iptables-ipset-proto4.conf iptables-ipset-proto6-allports.conf iptables-ipset-proto6.conf iptables-multiport-log.conf iptables-multiport.conf iptables-new.conf iptables-xt_recent-echo.conf iptables.conf mail-buffered.conf mail-whois-common.conf mail-whois-lines.conf mail-whois.conf mail.conf mynetwatchman.conf netscaler.conf nftables-allports.conf nftables-multiport.conf nftables.conf nginx-block-map.conf npf.conf nsupdate.conf osx-afctl.conf osx-ipfw.conf pf.conf route.conf sendmail-buffered.conf sendmail-common.conf sendmail-geoip-lines.conf sendmail-whois-ipjailmatches.conf sendmail-whois-ipmatches.conf sendmail-whois-lines.conf sendmail-whois-matches.conf sendmail-whois.conf sendmail.conf shorewall-ipset-proto6.conf shorewall.conf smtp.py symbiosis-blacklist-allports.conf ufw.conf xarf-login-attack.conf
CONF_FILES+=		${EGDIR}/action.d/${action} ${PKG_SYSCONFDIR}/action.d/${action}
.endfor


.for filter in 3proxy.conf apache-auth.conf apache-badbots.conf apache-botsearch.conf apache-common.conf apache-modsecurity.conf apache-nohome.conf apache-noscript.conf apache-overflows.conf apache-pass.conf apache-shellshock.conf assp.conf asterisk.conf bitwarden.conf botsearch-common.conf centreon.conf common.conf counter-strike.conf courier-auth.conf courier-smtp.conf cyrus-imap.conf directadmin.conf domino-smtp.conf dovecot.conf dropbear.conf drupal-auth.conf ejabberd-auth.conf exim-common.conf exim-spam.conf exim.conf freeswitch.conf froxlor-auth.conf groupoffice.conf gssftpd.conf guacamole.conf haproxy-http-auth.conf horde.conf kerio.conf lighttpd-auth.conf mongodb-auth.conf monit.conf murmur.conf mysqld-auth.conf nagios.conf named-refused.conf nginx-botsearch.conf nginx-http-auth.conf nginx-limit-req.conf nsd.conf openhab.conf openwebmail.conf oracleims.conf pam-generic.conf perdition.conf php-url-fopen.conf phpmyadmin-syslog.conf portsentry.conf postfix.conf proftpd.conf pure-ftpd.conf qmail.conf recidive.conf roundcube-auth.conf screensharingd.conf selinux-common.conf selinux-ssh.conf sendmail-auth.conf sendmail-reject.conf sieve.conf slapd.conf sogo-auth.conf solid-pop3d.conf squid.conf squirrelmail.conf sshd.conf stunnel.conf suhosin.conf tine20.conf traefik-auth.conf uwimap-auth.conf vsftpd.conf webmin-auth.conf wuftpd.conf xinetd-fail.conf znc-adminlog.conf zoneminder.conf
CONF_FILES+=		${EGDIR}/filter.d/${filter} ${PKG_SYSCONFDIR}/filter.d/${filter}
.endfor

CONF_FILES+=		${EGDIR}/filter.d/ignorecommands/apache-fakegooglebot ${PKG_SYSCONFDIR}/filter.d/ignorecommands/apache-fakegooglebot

TXTDOCFILES+=		develop.txt fail2ban.client.actionreader.txt fail2ban.client.beautifier.txt fail2ban.client.configparserinc.txt fail2ban.client.configreader.txt fail2ban.client.configurator.txt fail2ban.client.csocket.txt fail2ban.client.fail2banreader.txt fail2ban.client.filterreader.txt fail2ban.client.jailreader.txt fail2ban.client.jailsreader.txt fail2ban.client.txt fail2ban.exceptions.txt fail2ban.helpers.txt fail2ban.protocol.txt fail2ban.txt fail2ban.server.action.txt fail2ban.server.actions.txt fail2ban.server.asyncserver.txt fail2ban.server.banmanager.txt fail2ban.server.database.txt fail2ban.server.datedetector.txt fail2ban.server.datetemplate.txt fail2ban.server.failmanager.txt fail2ban.server.failregex.txt fail2ban.server.filter.txt fail2ban.server.filtergamin.txt fail2ban.server.filterpoll.txt fail2ban.server.filterpyinotify.txt fail2ban.server.filtersystemd.txt fail2ban.server.jail.txt fail2ban.server.jails.txt fail2ban.server.jailthread.txt fail2ban.server.mytime.txt fail2ban.server.txt fail2ban.server.server.txt fail2ban.server.strptime.txt fail2ban.server.ticket.txt fail2ban.server.transmitter.txt fail2ban.server.utils.txt fail2ban.version.txt filters.txt index.txt release.txt

AUTO_MKDIRS=		yes
MANPAGES1=		fail2ban-client.1 fail2ban-regex.1 fail2ban-server.1 fail2ban-testcases.1 fail2ban.1
MANPAGES5=		jail.conf.5

FILES_SUBST+=		PYTHON_INTERP=${PYTHONBIN:Q}
BUILD_DEFS+=		PYTHON_INTERP
BUILD_DEFS+=		VARBASE
RCD_SCRIPTS=		fail2ban

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Substituting paths variables.
SUBST_FILES.paths=	fail2ban/client/*.py
SUBST_FILES.paths+=	fail2ban/tests/utils.py
SUBST_FILES.paths+=	man/fail2ban-client.1
SUBST_FILES.paths+=	man/fail2ban-client.h2m
SUBST_FILES.paths+=	setup.py
SUBST_FILES.paths+=	config/fail2ban.conf
SUBST_FILES.paths+=	config/jail.conf
SUBST_FILES.paths+=	config/paths-pkgsrc.conf
SUBST_SED.paths=	-e 's,/etc,${PREFIX}/etc,g'
SUBST_SED.paths+=	-e 's,/var/lib,${VARBASE}/db,g'
SUBST_SED.paths+=	-e 's,/var,${VARBASE},g'
SUBST_SED.paths+=	-e 's,/usr/share,${PREFIX}/share,g'
SUBST_SED.paths+=	-e 's,paths-debian.conf,paths-pkgsrc.conf,g'
SUBST_VARS.paths=	VARBASE

SUBST_CLASSES+=		install
SUBST_STAGE.install=	pre-install
SUBST_MESSAGE.install=	correcting installation path
SUBST_FILES.install=	setup.py
SUBST_SED.install=	-e 's,${PREFIX}/etc/fail2ban,${EGDIR},g'

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		ostype
SUBST_STAGE.ostype=	post-configure
SUBST_MESSAGE.ostype=	Adjusting OS type
SUBST_FILES.ostype=	config/paths-pkgsrc.conf
.if ${OPSYS} == "NetBSD"
SUBST_SED.ostype=	-e "s,\#before = paths-distro.conf,before = paths-netbsd.conf,g"
.elif ${OPSYS} == "Darwin"
SUBST_SED.ostype=	-e "s,\#before = paths-distro.conf,before = paths-osx.conf,g"
.elif ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
SUBST_SED.ostype=	-e "s,\#before = paths-distro.conf,before = paths-freebsd.conf,g"
.else
SUBST_SED.ostype=	-e 's,this cant be empty,,g'
SUBST_NOOP_OK.ostype=	yes
.endif


post-extract:
	${CP} ${FILESDIR}/paths-netbsd.conf ${WRKSRC}/config/paths-netbsd.conf
	${CP} ${FILESDIR}/paths-pkgsrc.conf ${WRKSRC}/config/paths-pkgsrc.conf

pre-patch:
	cd ${WRKSRC}/ && ${PREFIX}/bin/2to3-${PYVERSSUFFIX} --no-diffs --write --nobackups --fix=all bin/* fail2ban

post-build:
	cd ${WRKSRC}/doc/ && make SPHINXBUILD=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX} text

post-install:
.for manfile1 in ${MANPAGES1}
	${INSTALL_MAN} ${WRKSRC}/man/${manfile1} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
.for manfile5 in ${MANPAGES5}
	${INSTALL_MAN} ${WRKSRC}/man/${manfile5} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/
.endfor
.for txt1 in ${TXTDOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/build/text/${txt1} ${DESTDIR}${DOCDIR}/
.endfor
.for txt2 in DEVELOP FILTERS README.Solaris README.md doc/run-rootless.txt
	${INSTALL_DATA} ${WRKSRC}/${txt2} ${DESTDIR}${DOCDIR}/
.endfor

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
