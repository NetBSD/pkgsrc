# $NetBSD: Makefile,v 1.5 2011/05/02 10:11:34 adam Exp $

DISTNAME=	knock-0.5
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.zeroflux.org/proj/knock/files/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.zeroflux.org/projects/knock/
COMMENT=	Port knocking server
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
