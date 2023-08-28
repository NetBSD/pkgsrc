# $NetBSD: Makefile,v 1.1 2023/08/28 16:26:10 vins Exp $

DISTNAME=	filter-rspamd-0.1.8
PKGNAME=	${DISTNAME:S|^|opensmtpd-|}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=poolpOrg/}
GITHUB_PROJECT=	filter-rspamd
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/poolpOrg/filter-rspamd/
COMMENT=	OpenSMTPD filter integration for the Rspamd daemon
LICENSE=	isc

DEPENDS+=	opensmtpd-[0-9]*:../../mail/opensmtpd
DEPENDS+=	rspamd-[0-9]*:../../mail/rspamd

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	README.rspamd
SUBST_VARS.conf=	PKG_SYSCONFDIR
SUBST_MESSAGE.conf=	Replacing pkgsrc placeholders.

GOPATH=	${WRKDIR}/.gopath

INSTALLATION_DIRS+=	libexec/opensmtpd ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/doc/opensmtpd/filters

post-extract:
	cp ${FILESDIR}/README.rspamd ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${GOPATH}/bin/filter-rspamd		\
		${DESTDIR}${PREFIX}/libexec/opensmtpd/
	${INSTALL_MAN} ${WRKSRC}/filter-rspamd.8		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.rspamd			\
		${DESTDIR}${PREFIX}/share/doc/opensmtpd/filters

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
