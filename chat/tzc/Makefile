# $NetBSD: Makefile,v 1.4 2004/04/25 00:39:04 wiz Exp $
#

DISTNAME=	tzc-2.6.15
CATEGORIES=	chat net
MASTER_SITES=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/zephyr.html
COMMENT=	Back-end program for zephyr-mode

CPPFLAGS+=      -I/usr/include/kerberosIV -I/usr/include/krb5
LDFLAGS+=       -lroken -lcrypto -lcom_err

USE_BUILDLINK3=	YES

.include "../zephyr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
