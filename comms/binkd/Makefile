# $NetBSD: Makefile,v 1.10 2001/02/20 11:40:09 wiz Exp $
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

GNU_CONFIGURE=		yes

NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64

post-extract:
	@cd ${WRKSRC}/mkfls/unix && ${CHMOD} +x configure mkinstalldirs && \
		${CP} * ../../

.include "../../mk/bsd.pkg.mk"
