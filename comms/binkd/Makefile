# $NetBSD: Makefile,v 1.9 2001/02/18 20:30:50 tv Exp $
#

DISTNAME=		binkd094
PKGNAME=		binkd-0.9.4
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		comms
MASTER_SITES=		http://www.corbina.net/~maloff/binkd/ \
			ftp://happy.kiev.ua/pub/fidosoft/mailer/binkd/
EXTRACT_SUFX=		.zip

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.corbina.net/~maloff/binkd/
COMMENT=		FidoNet-over-IP transport program utilizing BINKP protocol

BUILD_DEPENDS=		unzip:../../archivers/unzip

GNU_CONFIGURE=		yes
EXTRACT_CMD=		unzip -Loq ${DOWNLOADED_DISTFILE}

NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64

post-extract:
	@cd ${WRKSRC}/mkfls/unix && ${CHMOD} +x configure mkinstalldirs && \
		${CP} * ../../

.include "../../mk/bsd.pkg.mk"
