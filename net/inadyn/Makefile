# $NetBSD: Makefile,v 1.11 2016/03/05 11:29:05 jperkin Exp $

DISTNAME=	inadyn-1.99.13
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=troglobit/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://troglobit.com/inadyn.html
COMMENT=	Dynamic DNS client
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	autoconf gmake
RCD_SCRIPTS=	inadyn

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-openssl

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
	cd ${WRKSRC} && autoconf

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
