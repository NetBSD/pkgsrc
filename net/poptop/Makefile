# $NetBSD: Makefile,v 1.23 2026/08/04 20:29:12 wiz Exp $

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
SUBST_STAGE.sysconf=	pre-configure
SUBST_FILES.sysconf=	defaults.h pptpd.8 pptpd.conf.5
SUBST_SED.sysconf=	-e s,@@PKGSYSCONFDIR@@,${PKG_SYSCONFDIR},

SUBST_CLASSES+=		logwtmp
SUBST_STAGE.logwtmp=	pre-configure
SUBST_FILES.logwtmp=	pptpctrl.c
SUBST_SED.logwtmp=	-e s,@@PREFIX@@,${PREFIX},

RCD_SCRIPTS=	pptpd
CHECK_PORTABILITY_SKIP+=	version

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
