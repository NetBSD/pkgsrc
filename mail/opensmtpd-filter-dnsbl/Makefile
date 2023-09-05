# $NetBSD: Makefile,v 1.2 2023/09/05 13:42:32 vins Exp $

DISTNAME=	filter-dnsbl-0.3
PKGNAME=	${DISTNAME:S|^|opensmtpd-|}
CATEGORIES=	mail
MASTER_SITES=	https://imperialat.at/releases/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://imperialat.at/dev/filter-dnsbl/
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

MAKE_ENV+=		LOCALBASE=${PREFIX:Q}
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
