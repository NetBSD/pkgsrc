# $NetBSD: Makefile,v 1.6 2014/06/09 10:42:38 pettai Exp $

DISTNAME=	exabgp-exabgp-3.3.2
PKGNAME=	exabgp-3.3.2
CATEGORIES=	net
MASTER_SITES=	https://github.com/Exa-Networks/exabgp/tarball/3.3.2

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://github.com/Exa-Networks/exabgp/
COMMENT=	ExaBGP is a userspace BGP daemon written in python
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/Exa-Networks-exabgp-d73251b

USE_TOOLS+=	perl:run

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

EGG_NAME=	${PKGNAME_NOREV}
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 3.2.19

USE_LANGUAGES=  # none

INSTALLATION_DIRS=	bin/exabgp sbin

post-install:
	${LN} -s ${DESTDIR}${PREFIX}/bin/exabgp/exabgp \
			${DESTDIR}${PREFIX}/sbin/

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
