# $NetBSD: Makefile,v 1.11 2024/06/13 13:47:01 bsiegert Exp $

DISTNAME=	filter-senderscore-0.1.2
PKGNAME=	${DISTNAME:S|^|opensmtpd-|}
PKGREVISION=	10
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=poolpOrg/}
GITHUB_PROJECT=	filter-senderscore
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/poolpOrg/filter-senderscore/
COMMENT=	OpenSMTPD filter integration for SenderScore
LICENSE=	isc

DEPENDS+=	opensmtpd-[0-9]*:../../mail/opensmtpd

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	README.sscore
SUBST_VARS.prefix=	PKG_SYSCONFDIR PREFIX
SUBST_MESSAGE.prefix=	Replacing pkgsrc placeholders.

GOPATH=	${WRKDIR}/.gopath

INSTALLATION_DIRS+=	libexec/opensmtpd ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/doc/opensmtpd/filters

post-extract:
.for i in go.mod README.sscore
	${RUN}${CP} ${FILESDIR}/${i} ${WRKSRC}
.endfor

do-install:
	${INSTALL_PROGRAM} ${GOPATH}/bin/filter-senderscore	\
		${DESTDIR}${PREFIX}/libexec/opensmtpd/
	${INSTALL_MAN} ${WRKSRC}/filter-senderscore.8		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.sscore			\
		${DESTDIR}${PREFIX}/share/doc/opensmtpd/filters

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
