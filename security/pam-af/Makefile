# $NetBSD: Makefile,v 1.10 2011/10/17 09:38:25 obache Exp $

DISTNAME=	pam_af-1.0.2
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	security
MASTER_SITES=	http://mbsd.msk.ru/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mbsd.msk.ru/stas/pam_af.html
COMMENT=	Anti-bruteforce PAM module
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		pkgvar
SUBST_STAGE.pkgvar=	post-configure
SUBST_MESSAGE.pkgvar=	replace hard-coded paths
SUBST_FILES.pkgvar=	common/pam_af.h
SUBST_SED.pkgvar=	-e 's|/var/|${VARBASE}/|g'
SUBST_SED.pkgvar+=	-e 's|/etc/|${PKG_SYSCONFDIR}/|g'

BUILD_DEFS+=	VARBASE
MAKE_DIRS+=	${VARBASE}/db

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.include "../../databases/gdbm_compat/buildlink3.mk"
.endif
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
