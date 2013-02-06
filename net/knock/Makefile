# $NetBSD: Makefile,v 1.7 2013/02/06 19:30:58 jperkin Exp $

DISTNAME=	knock-0.5
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.zeroflux.org/proj/knock/files/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.zeroflux.org/projects/knock/
COMMENT=	Port knocking server
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

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

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
