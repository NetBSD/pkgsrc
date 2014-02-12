# $NetBSD: Makefile,v 1.16 2014/02/12 23:18:38 tron Exp $
#

DISTNAME=	adtool-1.2
PKGREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	http://gp2x.org/adtool/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gp2x.org/adtool/
COMMENT=	Active Directory administration utility for Unix

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PTHREAD_OPTS+=		require

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/adtool
CONF_FILES=		${EGDIR}/adtool.cfg.dist ${PKG_SYSCONFDIR}/adtool.cfg

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
