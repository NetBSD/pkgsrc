# $NetBSD: Makefile,v 1.1.1.1 2006/01/29 16:50:58 shannonjr Exp $

.include "../../net/snort/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-prelude-/}
PKGREVISION=	2

COMMENT=	Network Intrusion Detection System (with MySQL support)

CONFLICTS+=	snort-[0-9]*
CONFLICTS+=	snort-pgsql-[0-9]*
CONFLICTS+=	snort-mysql-[0-9]*

PKGDIR=		${.CURDIR}/../../net/snort
FILESDIR=	${PKGDIR}/files
PATCHDIR=	${PKGDIR}/patches
DISTINFO_FILE=	${PKGDIR}/distinfo

CONFIGURE_ARGS+=	--enable-prelude
CONFIGURE_ARGS+=	--localstatedir=/var/run
CONFIGURE_ARGS+=	--sharedstatedir=/var/run

.include "../../security/libprelude/buildlink3.mk"
.include "../../security/libpreludedb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
