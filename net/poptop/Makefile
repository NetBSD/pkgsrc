# $NetBSD: Makefile,v 1.21 2012/10/23 17:18:59 asau Exp $

DISTNAME=	pptpd-1.3.4
PKGNAME=	${DISTNAME:S/pptpd/poptop/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poptop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.poptop.org/
COMMENT=	PPTP server with support for Microsoft VPN clients
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libwrap

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	post-patch
SUBST_FILES.sysconf=	defaults.h pptpd.8 pptpd.conf.5
SUBST_SED.sysconf=	-e s,@@PKGSYSCONFDIR@@,${PKG_SYSCONFDIR},

SUBST_CLASSES+=		logwtmp
SUBST_STAGE.logwtmp=	post-patch
SUBST_FILES.logwtmp=	pptpctrl.c
SUBST_SED.logwtmp=	-e s,@@PREFIX@@,${PREFIX},

RCD_SCRIPTS=	pptpd
CHECK_PORTABILITY_SKIP+=	version

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
