# $NetBSD: Makefile,v 1.29 2010/01/07 07:36:54 wiz Exp $
#

DISTNAME=		binkd098
PKGNAME=		binkd-0.9.8
PKGREVISION=		2
CATEGORIES=		comms
MASTER_SITES=		ftp://happy.kiev.ua/pub/fidosoft/mailer/binkd/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://homepage.corbina.net/~maloff/binkd/
COMMENT=		FidoNet-over-IP transport program utilizing BINKP protocol

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

NOT_FOR_PLATFORM=	${LP64PLATFORMS}

post-extract:
	@cd ${WRKSRC}/mkfls/unix && ${CHMOD} +x configure mkinstalldirs && \
		${CP} * ../../

.include "../../mk/bsd.pkg.mk"
