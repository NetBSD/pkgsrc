# $NetBSD: Makefile,v 1.2 2021/05/25 17:29:42 nia Exp $

DISTNAME=		s-nail-14.9.22
CATEGORIES=		mail
MASTER_SITES=		https://www.sdaoden.eu/downloads/

MAINTAINER=		jgw@sdf.org
HOMEPAGE=		https://www.sdaoden.eu/code.html
COMMENT=		BSD mail utility with MIME extensions
LICENSE=		original-bsd AND osl AND mpl-1.1

MAKE_FILE=		makefile

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKE_FLAGS+=		VAL_MANDIR=${PREFIX}/${PKGMANDIR}
BUILD_MAKE_FLAGS+=	SYSCONFDIR=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

CONF_FILES=		${EGDIR}/s-nail.rc ${PKG_SYSCONFDIR}/s-nail.rc

.include "../../devel/libidn2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
