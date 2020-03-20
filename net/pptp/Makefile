# $NetBSD: Makefile,v 1.21 2020/03/20 11:58:10 nia Exp $

DISTNAME=	pptp-1.7.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pptpclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pptpclient.sourceforge.net/
COMMENT=	PPTP client package for Microsoft VPN servers
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

NOT_FOR_PLATFORM=	Interix-*-*

MAKE_FLAGS+=	BINDIR=${PREFIX}/sbin
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR:Q}/man8
MAKE_FLAGS+=	PPPDIR=${PREFIX}/share/examples/pptp

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 share/examples/pptp
INSTALLATION_DIRS+=	share/doc/pptp/Documentation share/doc/pptp/Reference
DOCDIR=			${PREFIX}/share/doc/pptp

post-install:
	cd ${WRKSRC}/Documentation && ${INSTALL_DATA} * ${DESTDIR}${DOCDIR}/Documentation
	cd ${WRKSRC}/Reference && ${INSTALL_DATA} * ${DESTDIR}${DOCDIR}/Reference
	cd ${WRKSRC} && ${INSTALL_DATA} INSTALL NEWS README USING ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.prefs.mk"

# Not quite yet---special config for MPPE in pppd.
.if defined(PPTP_USE_MPPE)
DEPENDS+=	pppd>=2.4.3:../../net/pppd
MAKE_FLAGS+=	PPPD=${PREFIX}/sbin/pppd
.else
MAKE_FLAGS+=	PPPD=/usr/sbin/pppd
.endif

SUBST_CLASSES+=		pptp
SUBST_MESSAGE.pptp=	"Fixing hardcoded paths."
SUBST_STAGE.pptp=	pre-configure
SUBST_FILES.pptp=	pptp.8
SUBST_SED.pptp=		-e 's,/usr,${PREFIX},g'

.include "../../mk/bsd.pkg.mk"
