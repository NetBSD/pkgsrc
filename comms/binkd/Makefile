# $NetBSD: Makefile,v 1.8 2001/02/16 13:56:11 wiz Exp $
#

DISTNAME=		binkd-0.9.2
CATEGORIES=		comms
MASTER_SITES=		http://www.corbina.net/~maloff/binkd/
EXTRACT_SUFX=		.zip

MAINTAINER=		tv@netbsd.org	# aka "Todd Vierling" @ 1:396/1.5
HOMEPAGE=		http://www.corbina.net/~maloff/binkd/
COMMENT=		FidoNet-over-IP transport program utilizing BINKP protocol

BUILD_DEPENDS=		unzip:../../archivers/unzip

GNU_CONFIGURE=		yes
EXTRACT_CMD=		unzip -Loq ${DOWNLOADED_DISTFILE}

NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64

post-extract:
	@cd ${WRKSRC}/mkfls/unix && ${CHMOD} +x configure && ${CP} * ../../

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binkd ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/binkd.8 ${PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/binkd.cfg ${PREFIX}/etc/binkd.cfg.dist

.include "../../mk/bsd.pkg.mk"
