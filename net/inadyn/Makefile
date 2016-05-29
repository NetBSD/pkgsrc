# $NetBSD: Makefile,v 1.13 2016/05/29 22:32:11 abs Exp $

DISTNAME=	inadyn-1.99.15
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=troglobit/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://troglobit.com/inadyn.html
COMMENT=	Dynamic DNS client
LICENSE=	gnu-gpl-v2

GITHUB_RELEASE=	1.99.15
GITHUB_TYPE=	release

USE_TOOLS+=	autoconf automake gmake
RCD_SCRIPTS=	inadyn

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-openssl --disable-gitcheck

LIBS.SunOS=	-lsocket -lnsl

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/doc/inadyn

OWN_DIRS+=		${VARBASE}/db/inadyn ${VARBASE}/run

BUILD_DEFS+=		VARBASE

SUBST_CLASSES+=		etc
SUBST_SED.etc=		-e "s|/etc|${PKG_SYSCONFDIR}|g"
SUBST_FILES.etc=	man/inadyn.conf.5 man/inadyn.8 include/ddns.h
SUBST_MESSAGE.etc=	Fixing path to configuration file
SUBST_STAGE.etc=	pre-configure

SUBST_CLASSES+=		var
SUBST_SED.var=		-e "s|/var|${VARBASE}|"
SUBST_FILES.var=	man/inadyn.conf.5 man/inadyn.8 include/ddns.h
SUBST_MESSAGE.var=	Adjusting path to VARBASE
SUBST_STAGE.var=	pre-configure

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libite/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
