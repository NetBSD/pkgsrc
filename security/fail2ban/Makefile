# $NetBSD: Makefile,v 1.36 2026/09/26 07:39:41 wiz Exp $

DISTNAME=	fail2ban-1.1.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=fail2ban/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/fail2ban/fail2ban
COMMENT=	Scans log files and bans IP that makes too many password failures
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-numpydoc>=0:../../textproc/py-numpydoc
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx>=0:../../textproc/py-sphinx

USE_LANGUAGES=	# none
USE_TOOLS+=	make:build

CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/fail2ban/tests/files/config/apache-auth/digest.py
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/fail2ban/tests/files/ignorecommand.py

EGDIR=			${PREFIX}/share/examples/fail2ban
PKG_SYSCONFSUBDIR=	fail2ban
DOCDIR=			${PREFIX}/share/doc/fail2ban
OWN_DIRS=		${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/action.d ${PKG_SYSCONFDIR}/filter.d \
			${VARBASE}/run/fail2ban ${VARBASE}/db/fail2ban
INSTALLATION_DIRS+=	${DOCDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

.include "config.mk"

.for f in ${EGFILES}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

TXTDOCFILES+=		develop.txt fail2ban.client.actionreader.txt fail2ban.client.beautifier.txt fail2ban.client.configparserinc.txt fail2ban.client.configreader.txt fail2ban.client.configurator.txt fail2ban.client.csocket.txt fail2ban.client.fail2banreader.txt fail2ban.client.filterreader.txt fail2ban.client.jailreader.txt fail2ban.client.jailsreader.txt fail2ban.client.txt fail2ban.exceptions.txt fail2ban.helpers.txt fail2ban.protocol.txt fail2ban.txt fail2ban.server.action.txt fail2ban.server.actions.txt fail2ban.server.asyncserver.txt fail2ban.server.banmanager.txt fail2ban.server.database.txt fail2ban.server.datedetector.txt fail2ban.server.datetemplate.txt fail2ban.server.failmanager.txt fail2ban.server.failregex.txt fail2ban.server.filter.txt fail2ban.server.filterpoll.txt fail2ban.server.filterpyinotify.txt fail2ban.server.filtersystemd.txt fail2ban.server.jail.txt fail2ban.server.jails.txt fail2ban.server.jailthread.txt fail2ban.server.mytime.txt fail2ban.server.txt fail2ban.server.server.txt fail2ban.server.strptime.txt fail2ban.server.ticket.txt fail2ban.server.transmitter.txt fail2ban.server.utils.txt fail2ban.version.txt filters.txt index.txt release.txt

MANPAGES1=		fail2ban-client.1 fail2ban-regex.1 fail2ban-server.1 fail2ban-testcases.1 fail2ban.1
MANPAGES5=		jail.conf.5

FILES_SUBST+=		PYTHON_INTERP=${PYTHONBIN:Q}
BUILD_DEFS+=		PYTHON_INTERP
BUILD_DEFS+=		VARBASE
RCD_SCRIPTS=		fail2ban

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Substituting paths variables.
SUBST_FILES.paths=	config/fail2ban.conf
SUBST_FILES.paths+=	config/jail.conf
SUBST_FILES.paths+=	config/paths-pkgsrc.conf
SUBST_FILES.paths+=	fail2ban/client/*.py
SUBST_FILES.paths+=	fail2ban/tests/utils.py
SUBST_FILES.paths+=	man/fail2ban-client.1
SUBST_FILES.paths+=	man/fail2ban-client.h2m
SUBST_SED.paths=	-e 's,/etc,${PREFIX}/etc,g'
SUBST_SED.paths+=	-e 's,/var/lib,${VARBASE}/db,g'
SUBST_SED.paths+=	-e 's,/var,${VARBASE},g'
SUBST_SED.paths+=	-e 's,/usr/share,${PREFIX}/share,g'
SUBST_SED.paths+=	-e 's,paths-debian.conf,paths-pkgsrc.conf,g'
SUBST_VARS.paths=	VARBASE

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

post-build:
	cd ${WRKSRC}/doc/ && ${MAKE} SPHINXBUILD=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX} text

post-install:
	${MV} ${DESTDIR}${PREFIX}/${PYSITELIB}/etc/fail2ban ${DESTDIR}${EGDIR}
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

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
