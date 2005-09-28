# $NetBSD: Makefile,v 1.21 2005/09/28 20:52:24 rillig Exp $
#

DISTNAME=	freeWAIS-sf-2.2.12
PKGNAME=	freewais-sf-2.2.12
PKGREVISION=	3
CATEGORIES=	net databases
MASTER_SITES=	ftp://ls6-ftp.cs.uni-dortmund.de/pub/src/freeWAIS-sf/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://ls6-www.informatik.uni-dortmund.de/ir/projects/freeWAIS-sf/index.html
COMMENT=	Enhanced Wide Area Information Server

NOT_FOR_PLATFORM=	Darwin-*-*

USE_LIBTOOL=	yes
USE_TOOLS+=	perl:run

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde -Dprefix=${PREFIX} \
			-Darchname=${MACHINE_ARCH}-${LOWER_OPSYS}
CONFIGURE_ENV+=		PERL5="${PERL5}"
INSTALL_TARGET=	install install.man

USE_MAKEINFO=	YES
INFO_FILES=	fwsf.info

post-build:
	cd ${WRKSRC}/doc/SF; ${MAKEINFO} fwsf.texi

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/SF/fwsf.info* ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
