# $NetBSD: Makefile,v 1.16 2006/11/11 16:50:54 rillig Exp $
#

DISTNAME=	pptpd-1.2.1
PKGNAME=	${DISTNAME:S/pptpd/poptop/}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poptop/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.poptop.org/
COMMENT=	PPTP server with support for Microsoft VPN clients

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

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
