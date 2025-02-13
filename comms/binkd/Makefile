# $NetBSD: Makefile,v 1.35 2025/02/13 06:25:39 dholland Exp $
#

DISTNAME=		binkd098
PKGNAME=		binkd-0.9.8
PKGREVISION=		2
CATEGORIES=		comms
MASTER_SITES=		ftp://happy.kiev.ua/pub/fidosoft/mailer/binkd/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://homepage.corbina.net/~maloff/binkd/
COMMENT=		FidoNet-over-IP transport program utilizing BINKP protocol

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} PREFIX=${DESTDIR}${PREFIX}

post-extract:
	(cd ${WRKSRC}/mkfls/unix && ${CHMOD} +x configure mkinstalldirs && \
		${CP} * ../../)

.include "../../mk/bsd.pkg.mk"
