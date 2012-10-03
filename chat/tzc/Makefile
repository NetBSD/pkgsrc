# $NetBSD: Makefile,v 1.15 2012/10/03 00:02:46 asau Exp $
#

DISTNAME=	tzc-2.6.15
PKGREVISION=	3
CATEGORIES=	chat net
MASTER_SITES=	http://www.cs.cmu.edu/People/dkindred/zephyr-mode/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.cmu.edu/People/dkindred/zephyr/zephyr.html
COMMENT=	Back-end program for zephyr-mode

CPPFLAGS+=	-I/usr/include/kerberosIV -I/usr/include/krb5
LDFLAGS+=	-lroken -lcrypto -lcom_err

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
LDFLAGS+=	-lcrypt
SUBST_CLASSES+=		FreeFly
SUBST_STAGE.FreeFly=	post-patch
SUBST_MESSAGE.FreeFly=	Removing unwanted libdes
SUBST_FILES.FreeFly=	Makefile
SUBST_SED.FreeFly=	-e 's,-lkrb -ldes,-lkrb,g'
.endif

INSTALLATION_DIRS+=	bin

.include "../../chat/zephyr/buildlink3.mk"
.include "../../security/kth-krb4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
