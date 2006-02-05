# $NetBSD: Makefile,v 1.6 2006/02/05 23:09:54 joerg Exp $
#

DISTNAME=	esmtp-0.5.1
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=esmtp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://esmtp.sourceforge.net/
COMMENT=	Relay-only Mail Transfer Agent with sendmail-compatible syntax

GNU_CONFIGURE=		yes
USE_TOOLS+=		bison flex
PTHREAD_OPTS+=		require

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	README esmtp.1 esmtprc.5 sample.esmtprc
SUBST_SED.paths=	-e 's|/usr/bin|${PREFIX}/bin|g'
SUBST_SED.paths+=	-e 's|/etc|${PKG_SYSCONFDIR}|g'

PKG_SYSCONFSUBDIR=	esmtp

EGDIR=			${PREFIX}/share/examples/esmtp
CONF_FILES=		${EGDIR}/sample.esmtprc \
			${PKG_SYSCONFDIR}/esmtprc

.include "../../mail/libesmtp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/esmtp
	${INSTALL_DATA} ${WRKSRC}/sample.esmtprc ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/esmtp

.include "../../mk/bsd.pkg.mk"
