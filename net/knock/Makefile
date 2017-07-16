# $NetBSD: Makefile,v 1.8 2017/07/16 21:25:06 adam Exp $

DISTNAME=	knock-0.7
CATEGORIES=	net
MASTER_SITES=	http://www.zeroflux.org/proj/knock/files/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.zeroflux.org/projects/knock/
COMMENT=	Port knocking server
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${EGDIR}

BUILD_DEFS+=	VARBASE

EGDIR=		${PREFIX}/share/examples/knock
CONF_FILES=	${EGDIR}/knockd.conf ${PKG_SYSCONFDIR}/knockd.conf

INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8 ${EGDIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths=	src/knockd.c
SUBST_SED.paths=	-e 's,"/etc,"${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,"/var,"${VARBASE},g'

post-install:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR} && ${MV} man1/knockd.1 man8/knockd.8 || ${TRUE}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
