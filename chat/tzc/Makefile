# $NetBSD: Makefile,v 1.8 2006/02/05 23:08:26 joerg Exp $
#

DISTNAME=	tzc-2.6.15
PKGREVISION=	2
CATEGORIES=	chat net
MASTER_SITES=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/zephyr.html
COMMENT=	Back-end program for zephyr-mode

CPPFLAGS+=      -I/usr/include/kerberosIV -I/usr/include/krb5
LDFLAGS+=       -lroken -lcrypto -lcom_err

.include "../../chat/zephyr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
