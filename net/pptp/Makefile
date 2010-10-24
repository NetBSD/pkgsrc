# $NetBSD: Makefile,v 1.14 2010/10/24 16:16:28 pettai Exp $

DISTNAME=	pptp-1.7.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pptpclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pptpclient.sourceforge.net/
COMMENT=	PPTP client package for Microsoft VPN servers (no encryption yet)
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

NOT_FOR_PLATFORM=	Interix-*-*

MAKE_FLAGS+=	BINDIR=${PREFIX}/sbin
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR:Q}/man8
MAKE_FLAGS+=	PPPDIR=${PREFIX}/share/examples/pptp

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 share/examples/pptp
INSTALLATION_DIRS+=	share/doc/pptp/Documentation share/doc/pptp/Reference
DOCDIR=		${PREFIX}/share/doc/pptp

post-install:
	cd ${WRKSRC}/Documentation && ${INSTALL_DATA} * ${DESTDIR}${DOCDIR}/Documentation
	cd ${WRKSRC}/Reference && ${INSTALL_DATA} * ${DESTDIR}${DOCDIR}/Reference
	cd ${WRKSRC} && ${INSTALL_DATA} INSTALL NEWS README USING ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.prefs.mk"

# Not quite yet---special config for MPPE in pppd.
#.if defined(PPTP_USE_MPPE)
#DEPENDS+=	ppp-mppe-2.3.9:../../net/ppp-mppe
#CONFIGURE_ARGS+= --with-pppd=${PREFIX}/sbin/pppd
#.endif

.include "../../mk/bsd.pkg.mk"
