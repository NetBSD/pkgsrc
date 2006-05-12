# $NetBSD: Makefile,v 1.11 2006/05/12 09:30:55 joerg Exp $

DISTNAME=	pptp-1.7.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pptpclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pptpclient.sourceforge.net/
COMMENT=	PPTP client package for Microsoft VPN servers (no encryption yet)

NOT_FOR_PLATFORM=	Interix-*-*

MAKE_ENV+=	ROOT_USER=${ROOT_USER}
MAKE_FLAGS+=	BINDIR=${PREFIX:Q}/sbin
MAKE_FLAGS+=	MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}/man8
MAKE_FLAGS+=	PPPDIR=${PREFIX:Q}/share/examples/pptp

INSTALLATION_DIRS=	bin ${PKGMANDIR:Q}/man8 share/examples/pptp
INSTALLATION_DIRS+=	share/doc/pptp/Documentation share/doc/pptp/Reference
DOCDIR=		${PREFIX}/share/doc/pptp

post-install:
	cd ${WRKSRC:Q}/Documentation && ${INSTALL_DATA} * ${DOCDIR:Q}/Documentation
	cd ${WRKSRC:Q}/Reference && ${INSTALL_DATA} * ${DOCDIR:Q}/Reference
	cd ${WRKSRC:Q} && ${INSTALL_DATA} INSTALL NEWS README USING ${DOCDIR:Q}

.include "../../mk/bsd.prefs.mk"

# Not quite yet---special config for MPPE in pppd.
#.if defined(PPTP_USE_MPPE)
#DEPENDS+=	ppp-mppe-2.3.9:../../net/ppp-mppe
#CONFIGURE_ARGS+= --with-pppd=${PREFIX}/sbin/pppd
#.endif

.include "../../mk/bsd.pkg.mk"
