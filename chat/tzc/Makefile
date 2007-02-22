# $NetBSD: Makefile,v 1.11 2007/02/22 19:26:12 wiz Exp $
#

DISTNAME=	tzc-2.6.15
PKGREVISION=	3
CATEGORIES=	chat net
MASTER_SITES=	http://www.cs.cmu.edu/People/dkindred/zephyr-mode/

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://www.cs.cmu.edu/People/dkindred/zephyr/zephyr.html
COMMENT=	Back-end program for zephyr-mode

CPPFLAGS+=	-I/usr/include/kerberosIV -I/usr/include/krb5
LDFLAGS+=	-lroken -lcrypto -lcom_err

.include "../../chat/zephyr/buildlink3.mk"
.include "../../security/kth-krb4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
