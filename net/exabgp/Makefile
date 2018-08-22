# $NetBSD: Makefile,v 1.25 2018/08/22 09:45:52 wiz Exp $

VERSION=	3.4.23
DISTNAME=	${VERSION}
PKGNAME=	exabgp-${VERSION}
PKGREVISION=	1
EGG_NAME=	exabgp-${VERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Exa-Networks/exabgp/archive/}
DIST_SUBDIR=	exabgp

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://github.com/Exa-Networks/exabgp/
COMMENT=	ExaBGP is a userspace BGP daemon written in python
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/exabgp-${VERSION}

USE_TOOLS+=	perl:run

DEPENDS+=	${PYPKGPREFIX}-ipaddr>=0:../../devel/py-ipaddr
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

REPLACE_PERL+=		etc/exabgp/processes/dynamic-1.pl
REPLACE_PERL+=		etc/exabgp/processes/watchdog-1.pl

REPLACE_PYTHON+=	etc/exabgp/processes/read-write.py
REPLACE_PYTHON+=	etc/exabgp/processes/stderr-1.py
REPLACE_PYTHON+=	etc/exabgp/processes/syslog-1.py
REPLACE_PYTHON+=	etc/exabgp/processes/tcp-server
REPLACE_PYTHON+=	lib/exabgp/application/bmp.py
REPLACE_PYTHON+=	lib/exabgp/application/cli.py
REPLACE_PYTHON+=	lib/exabgp/application/healthcheck.py
REPLACE_PYTHON+=	lib/exabgp/application/netlink.py
REPLACE_PYTHON+=	lib/exabgp/netlink/old.py
REPLACE_PYTHON+=	lib/exabgp/reactor/api/encoding.py
REPLACE_PYTHON+=	qa/conf/api-add-remove.run
REPLACE_PYTHON+=	qa/conf/api-announcement.run
REPLACE_PYTHON+=	qa/conf/api-api.nothing.run
REPLACE_PYTHON+=	qa/conf/api-api.receive.run
REPLACE_PYTHON+=	qa/conf/api-broken-flow.run
REPLACE_PYTHON+=	qa/conf/api-check.run
REPLACE_PYTHON+=	qa/conf/api-eor.run
REPLACE_PYTHON+=	qa/conf/api-fast.run
REPLACE_PYTHON+=	qa/conf/api-flow.run
REPLACE_PYTHON+=	qa/conf/api-multi-neighbor.run
REPLACE_PYTHON+=	qa/conf/api-multisession.run
REPLACE_PYTHON+=	qa/conf/api-nexthop-self.run
REPLACE_PYTHON+=	qa/conf/api-nexthop.run
REPLACE_PYTHON+=	qa/conf/api-notification.run
REPLACE_PYTHON+=	qa/conf/api-open.run
REPLACE_PYTHON+=	qa/conf/api-reload.run
REPLACE_PYTHON+=	qa/conf/api-teardown.run
REPLACE_PYTHON+=	qa/conf/api-vpls.run
REPLACE_PYTHON+=	qa/conf/api-vpnv4.run
REPLACE_PYTHON+=	qa/conf/manual-eor.run
REPLACE_PYTHON+=	qa/conf/watchdog.run

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 3.2.19

USE_LANGUAGES=  # none

INSTALLATION_DIRS+=	share/exabgp bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

pre-install:
	find ${WRKDIR} -name "*.orig" | xargs rm -f

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/exabgp.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/exabgp.conf.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
