# $NetBSD: Makefile,v 1.31 2005/08/07 16:43:15 recht Exp $
#

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/BitT/bitt/}

PYDISTUTILSPKG=	YES

CONFLICTS+=	bittornado-[0-9]*

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		blibc
SUBST_STAGE.blibc=	pre-configure
SUBST_FILES.blibc=	BitTorrent/defaultargs.py

# Enable the 'enable_bad_libc_workaround' on BSD by default.
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" \
	|| ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly"
SUBST_SED.blibc=		-e s/%BSD_LIBC%/1/g
.else
SUBST_SED.blibc=		-e s/%BSD_LIBC%/0/g
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-cursespanel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
