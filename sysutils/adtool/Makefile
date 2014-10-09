# $NetBSD: Makefile,v 1.17 2014/10/09 14:06:56 wiz Exp $
#

DISTNAME=	adtool-1.2
PKGREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	http://gp2x.org/adtool/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gp2x.org/adtool/
COMMENT=	Active Directory administration utility for Unix

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
