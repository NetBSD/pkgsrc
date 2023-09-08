# $NetBSD: Makefile,v 1.6 2023/09/08 20:53:17 vins Exp $

DISTNAME=	libasr-1.0.4
CATEGORIES=	net
MASTER_SITES=	https://www.opensmtpd.org/archives/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenSMTPD/libasr
COMMENT=	Asynchronous DNS resolver library
LICENSE=	isc AND modified-bsd AND 2-clause-bsd

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CFLAGS.NetBSD+=		-D_OPENBSD_SOURCE   # strtonum()

INSTALLATION_DIRS+=	${PKGMANDIR}/man3

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/asr_run.3	\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
