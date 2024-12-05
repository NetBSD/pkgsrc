# $NetBSD: Makefile,v 1.1 2024/12/05 09:08:30 vins Exp $

DISTNAME=	filter-spfgreylist-1.0.0
PKGNAME=	${DISTNAME:S|^|opensmtpd-|}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=poolpOrg/}
GITHUB_PROJECT=	filter-spfgreylist
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/poolpOrg/filter-spfgreylist/
COMMENT=	SPF-aware greylisting filter integration for OpenSMTPD
LICENSE=	isc

DEPENDS+=	opensmtpd-[0-9]*:../../mail/opensmtpd

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	README.spf
SUBST_VARS.prefix=	PKG_SYSCONFDIR PREFIX
SUBST_MESSAGE.prefix=	Replacing pkgsrc placeholders.

GOPATH=	${WRKDIR}/.gopath

INSTALLATION_DIRS+=	libexec/opensmtpd
INSTALLATION_DIRS+=	share/doc/opensmtpd/filters

post-extract:
	${RUN}${CP} ${FILESDIR}/README.spf ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${GOPATH}/bin/filter-spfgreylist		\
		${DESTDIR}${PREFIX}/libexec/opensmtpd/

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.spf			\
		${DESTDIR}${PREFIX}/share/doc/opensmtpd/filters

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
