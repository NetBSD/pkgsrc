# $NetBSD: Makefile,v 1.13 2002/11/14 23:50:45 jlam Exp $
#

DISTNAME=		binkd094
PKGNAME=		binkd-0.9.4
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		comms
MASTER_SITES=		http://www.corbina.net/~maloff/binkd/ \
			ftp://happy.kiev.ua/pub/fidosoft/mailer/binkd/
EXTRACT_SUFX=		.zip

MAINTAINER=		tv@pobox.com
HOMEPAGE=		http://www.corbina.net/~maloff/binkd/
COMMENT=		FidoNet-over-IP transport program utilizing BINKP protocol

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64

post-extract:
	@cd ${WRKSRC}/mkfls/unix && ${CHMOD} +x configure mkinstalldirs && \
		${CP} * ../../

.include "../../mk/bsd.pkg.mk"
