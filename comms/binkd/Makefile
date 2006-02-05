# $NetBSD: Makefile,v 1.23 2006/02/05 23:08:27 joerg Exp $
#

DISTNAME=		binkd098
PKGNAME=		binkd-0.9.8
PKGREVISION=		2
CATEGORIES=		comms
MASTER_SITES=		http://www.corbina.net/~maloff/binkd/ \
			ftp://happy.kiev.ua/pub/fidosoft/mailer/binkd/
EXTRACT_SUFX=		.zip

MAINTAINER=		tv@pobox.com
HOMEPAGE=		http://www.corbina.net/~maloff/binkd/
COMMENT=		FidoNet-over-IP transport program utilizing BINKP protocol

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64

post-extract:
	@cd ${WRKSRC}/mkfls/unix && ${CHMOD} +x configure mkinstalldirs && \
		${CP} * ../../

.include "../../mk/bsd.pkg.mk"
