# $NetBSD: Makefile,v 1.8 2025/09/13 16:19:20 vins Exp $

DISTNAME=	filter-dnsbl-0.4
PKGNAME=	${DISTNAME:S|^|opensmtpd-|}
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	https://src.imperialat.at/releases/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://src.imperialat.at/?action=summary&path=filter-dnsbl.git
COMMENT=	OpenSMTPD filter integration for DNSBL lists
LICENSE=	isc

DEPENDS+=	opensmtpd-[0-9]*:../../mail/opensmtpd

USE_BSD_MAKEFILE=	yes

CFLAGS.Linux+=		-D_GNU_SOURCE #strcasestr()

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	README.dnsbl
SUBST_VARS.prefix=	PKG_SYSCONFDIR PREFIX
SUBST_MESSAGE.prefix=	Replacing pkgsrc placeholders

MAKE_ENV+=		LOCALBASE=${PREFIX}
MAKE_ENV+=		BINDIR=${PREFIX}/libexec/opensmtpd
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}

INSTALL_ENV=		INSTALL=${INSTALL:Q}
INSTALL_TARGET=		bindir install
INSTALLATION_DIRS+=	libexec/opensmtpd ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/doc/opensmtpd/filters

post-extract:
	${RUN}${CP} ${FILESDIR}/README.* ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.dnsbl		\
		${DESTDIR}${PREFIX}/share/doc/opensmtpd/filters

.include "../../devel/libopensmtpd/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../net/libasr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
