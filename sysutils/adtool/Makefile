# $NetBSD: Makefile,v 1.1.1.1 2004/10/30 21:11:56 minskim Exp $
#

DISTNAME=	adtool-1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://c128.org/adtool/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://c128.org/adtool/
COMMENT=	Active Directory administration utility for Unix

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/adtool
CONF_FILES=		${EGDIR}/adtool.cfg.dist ${PKG_SYSCONFDIR}/adtool.cfg

.include "../../databases/openldap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
