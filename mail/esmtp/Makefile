# $NetBSD: Makefile,v 1.14 2014/02/12 23:18:07 tron Exp $
#

DISTNAME=	esmtp-1.2
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=esmtp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://esmtp.sourceforge.net/
COMMENT=	Relay-only Mail Transfer Agent with sendmail-compatible syntax
LICENSE=	gnu-gpl-v2

CONFLICTS+=	courier-mta-[0-9]* fastforward>=0.51nb2 postfix-[0-9]*
CONFLICTS+=	sendmail-[0-9]*

GNU_CONFIGURE=		yes
USE_TOOLS+=		bison flex
PTHREAD_OPTS+=		require

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	README esmtp.1 esmtprc.5 sample.esmtprc
SUBST_SED.paths=	-e 's|/usr/bin|${PREFIX}/bin|g'
SUBST_SED.paths+=	-e 's|/etc|${PKG_SYSCONFDIR}|g'

PKG_SYSCONFSUBDIR=	esmtp

EGDIR=			${PREFIX}/share/examples/esmtp
CONF_FILES=		${EGDIR}/sample.esmtprc \
			${PKG_SYSCONFDIR}/esmtprc

INSTALLATION_DIRS=	${EGDIR} share/doc/esmtp

.include "../../mail/libesmtp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/sample.esmtprc ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/esmtp

.include "../../mk/bsd.pkg.mk"
