# $NetBSD: Makefile,v 1.2 2000/03/27 08:54:59 tron Exp $
#

DISTNAME=	freeWAIS-sf-2.2.12
PKGNAME=	freewais-sf-2.2.12
CATEGORIES=	net databases
MASTER_SITES=	ftp://ls6-ftp.cs.uni-dortmund.de/pub/src/freeWAIS-sf/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://ls6-www.informatik.uni-dortmund.de/ir/projects/freeWAIS-sf/index.html

BUILD_DEPENDS=	${LOCALBASE}/bin/perl:../../lang/perl5

USE_LIBTOOL=	yes

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde -Dprefix=${PREFIX} \
				-Darchname=${MACHINE_ARCH}-${LOWER_OPSYS}
INSTALL_TARGET=	install install.man

INFO_FILES=	fwsf.info

post-build:
	(cd ${WRKSRC}/doc/SF; makeinfo fwsf.texi)

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/SF/fwsf.info* ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
