# $NetBSD: Makefile,v 1.6 2024/01/17 23:43:02 gdt Exp $

DISTNAME=		s-nail-14.9.24
CATEGORIES=		mail
MASTER_SITES=		https://www.sdaoden.eu/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.sdaoden.eu/code.html
COMMENT=		BSD mail utility with MIME extensions
LICENSE=		original-bsd AND osl AND mpl-1.1

MAKE_FILE=		makefile

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKE_FLAGS+=		VAL_PREFIX=${PREFIX}
MAKE_FLAGS+=		VAL_MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		OPT_AUTOCC=no
INSTALL_MAKE_FLAGS+=	PKGBASE=${PKGBASE}

CONF_FILES=		${EGDIR}/s-nail.rc ${PKG_SYSCONFDIR}/s-nail.rc

.include "../../devel/libidn2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
