# $NetBSD: Makefile,v 1.16 2004/10/03 00:17:51 tv Exp $
#

DISTNAME=	freeWAIS-sf-2.2.12
PKGNAME=	freewais-sf-2.2.12
PKGREVISION=	2
CATEGORIES=	net databases
MASTER_SITES=	ftp://ls6-ftp.cs.uni-dortmund.de/pub/src/freeWAIS-sf/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://ls6-www.informatik.uni-dortmund.de/ir/projects/freeWAIS-sf/index.html
COMMENT=	Enhanced Wide Area Information Server

USE_BUILDLINK3=	yes
USE_PERL5=	build
USE_LIBTOOL=	# defined

HAS_CONFIGURE=		# defined
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde -Dprefix=${PREFIX} \
			-Darchname=${MACHINE_ARCH}-${LOWER_OPSYS}
INSTALL_TARGET=	install install.man

USE_MAKEINFO=	YES
INFO_FILES=	fwsf.info

post-build:
	cd ${WRKSRC}/doc/SF; ${MAKEINFO} fwsf.texi

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/SF/fwsf.info* ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
