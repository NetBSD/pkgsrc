# $NetBSD: Makefile,v 1.19 2022/01/01 12:59:15 rhialto Exp $

DISTNAME=	pam_af-1.0.2
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://mbsd.msk.ru/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://mbsd.msk.ru/stas/pam_af.html
COMMENT=	Anti-bruteforce PAM module
LICENSE=	2-clause-bsd

SUBST_CLASSES+=		pkgvar
SUBST_STAGE.pkgvar=	post-configure
SUBST_MESSAGE.pkgvar=	replace hard-coded paths
SUBST_FILES.pkgvar=	common/pam_af.h
SUBST_SED.pkgvar=	-e 's|/var/|${VARBASE}/|g'
SUBST_SED.pkgvar+=	-e 's|/etc/|${PKG_SYSCONFDIR}/|g'

BUILD_DEFS+=	VARBASE
MAKE_DIRS+=	${VARBASE}/db

BUILDLINK_TRANSFORM+=	rm:-Wcast-qual

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.include "../../databases/gdbm_compat/buildlink3.mk"
.endif
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
