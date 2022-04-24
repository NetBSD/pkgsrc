# $NetBSD: Makefile,v 1.20 2022/04/24 01:35:38 tnn Exp $
#

DISTNAME=		rinetd-0.73
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=samhocevar/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/samhocevar/rinetd
COMMENT=		Internet redirection server
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

CPPFLAGS.NetBSD+=	-D_NETBSD_SOURCE # for SA_RESTART
CPPFLAGS.SunOS+=	-D__EXTENSIONS__ # for SA_RESTART

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	src/rinetd.h
SUBST_SED.paths=	-e 's,/etc/rinetd.conf,${PKG_SYSCONFDIR}/rinetd.conf,'
SUBST_STAGE.paths=	pre-configure

RCD_SCRIPTS=		rinetd

INSTALLATION_DIRS=	share/examples/rinetd
EGDIR=			${PREFIX}/share/examples/rinetd
CONF_FILES=		${EGDIR}/rinetd.conf ${PKG_SYSCONFDIR}/rinetd.conf

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
