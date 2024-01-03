# $NetBSD: Makefile,v 1.5 2024/01/03 23:32:11 gdt Exp $

DISTNAME=		s-nail-14.9.22
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		https://www.sdaoden.eu/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
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
