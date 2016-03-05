# $NetBSD: Makefile,v 1.19 2016/03/05 11:29:27 jperkin Exp $
#

DISTNAME=	adtool-1.3.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://gp2x.org/adtool/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gp2x.org/adtool/
COMMENT=	Active Directory administration utility for Unix
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PTHREAD_OPTS+=		require

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/adtool
CONF_FILES=		${EGDIR}/adtool.cfg.dist ${PKG_SYSCONFDIR}/adtool.cfg
INSTALLATION_DIRS=	${EGDIR}

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/adtool.cfg.dist ${DESTDIR}${EGDIR}

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
