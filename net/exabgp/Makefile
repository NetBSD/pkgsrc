# $NetBSD: Makefile,v 1.10 2015/02/19 12:23:52 he Exp $

VERSION=	3.4.7
DISTNAME=	${VERSION}
PKGNAME=	exabgp-${VERSION}
EGG_NAME=	exabgp-${VERSION}
CATEGORIES=	net
MASTER_SITES=	https://github.com/Exa-Networks/exabgp/archive/
DIST_SUBDIR=	exabgp

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://github.com/Exa-Networks/exabgp/
COMMENT=	ExaBGP is a userspace BGP daemon written in python
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/exabgp-${VERSION}

USE_TOOLS+=	perl:run

DEPENDS+=	${PYPKGPREFIX}-ipaddr>=0:../../devel/py-ipaddr
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

REPLACE_PERL=		etc/exabgp/processes/dynamic-1.pl
REPLACE_PERL+=		etc/exabgp/processes/watchdog-1.pl
REPLACE_PYTHON=		lib/exabgp/application/bmp.py
REPLACE_PYTHON+=	lib/exabgp/bgp/message/update/nlri/eor.py
REPLACE_PYTHON+=	lib/exabgp/reactor/api/encoding.py
REPLACE_PYTHON+=	lib/netlink/route.py
REPLACE_PYTHON+=	lib/netlink/test/get.py
REPLACE_PYTHON+=	lib/netlink/test/route.py
REPLACE_PYTHON+=	etc/exabgp/processes/healthcheck.py
REPLACE_PYTHON+=	etc/exabgp/processes/read-write.py
REPLACE_PYTHON+=	etc/exabgp/processes/tcp-server
REPLACE_PYTHON+=	etc/exabgp/processes/syslog-1.py
REPLACE_PYTHON+=	etc/exabgp/processes/stderr-1.py

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 3.2.19

USE_LANGUAGES=  # none

INSTALLATION_DIRS=	share/exabgp bin

pre-install:
	find work -name '*.orig' | xargs rm -f

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
