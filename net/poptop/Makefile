# $NetBSD: Makefile,v 1.11 2005/01/12 12:28:04 cube Exp $
#

DISTNAME=	pptpd-1.2.1
PKGNAME=	${DISTNAME:S/pptpd/poptop/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poptop/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.poptop.org/
COMMENT=	PPTP server with support for Microsoft VPN clients

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_PKGINSTALL=	YES

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

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
