# $NetBSD: Makefile,v 1.1.1.1 1998/11/22 20:47:13 tv Exp $
#

DISTNAME=	binkd-0.9.2
CATEGORIES=	comms
MASTER_SITES=	http://www.corbina.net/~maloff/binkd/
EXTRACT_SUFX=	.zip

MAINTAINER=	tv@netbsd.org	# aka "Todd Vierling" @ 1:396/1.5
HOMEPAGE=	http://www.corbina.net/~maloff/binkd/

BUILD_DEPENDS=	unzip:../../archivers/unzip

GNU_CONFIGURE=	yes
EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS= -qo

NO_CDROM=	"extremely limited usefulness to the general public"

post-extract:
	@cd ${WRKSRC}/mkfls/unix && ${CHMOD} +x configure && ${CP} * ../../

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binkd ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/binkd.8 ${PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/binkd.cfg ${PREFIX}/etc/

.include "../../mk/bsd.pkg.mk"
