# $NetBSD: Makefile,v 1.5 2005/04/11 21:45:06 tv Exp $
#

DISTNAME=	tzc-2.6.15
CATEGORIES=	chat net
MASTER_SITES=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/zephyr.html
COMMENT=	Back-end program for zephyr-mode

CPPFLAGS+=      -I/usr/include/kerberosIV -I/usr/include/krb5
LDFLAGS+=       -lroken -lcrypto -lcom_err


.include "../zephyr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
