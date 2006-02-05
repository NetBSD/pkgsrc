# $NetBSD: Makefile,v 1.4 2006/02/05 23:10:31 joerg Exp $

.include "../../net/snort/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-prelude-/}
PKGREVISION=	3

COMMENT=	Network Intrusion Detection System (with Prelude support)

CONFLICTS+=	snort-[0-9]*
CONFLICTS+=	snort-pgsql-[0-9]*
CONFLICTS+=	snort-mysql-[0-9]*

PKGDIR=		${.CURDIR}/../../net/snort
FILESDIR=	${PKGDIR}/files
PATCHDIR=	${PKGDIR}/patches
DISTINFO_FILE=	${PKGDIR}/distinfo

CONFIGURE_ARGS+=	--enable-prelude
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/run
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE}/run

.include "../../security/libprelude/buildlink3.mk"
.include "../../security/libpreludedb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
