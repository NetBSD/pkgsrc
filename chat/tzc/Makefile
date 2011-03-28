# $NetBSD: Makefile,v 1.13 2011/03/28 13:11:21 obache Exp $
#

DISTNAME=	tzc-2.6.15
PKGREVISION=	3
CATEGORIES=	chat net
MASTER_SITES=	http://www.cs.cmu.edu/People/dkindred/zephyr-mode/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.cmu.edu/People/dkindred/zephyr/zephyr.html
COMMENT=	Back-end program for zephyr-mode

PKG_DESTDIR_SUPPORT=	user-destdir

CPPFLAGS+=	-I/usr/include/kerberosIV -I/usr/include/krb5
LDFLAGS+=	-lroken -lcrypto -lcom_err

INSTALLATION_DIRS+=	bin

.include "../../chat/zephyr/buildlink3.mk"
.include "../../security/kth-krb4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
