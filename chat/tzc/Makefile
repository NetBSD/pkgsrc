# $NetBSD: Makefile,v 1.3 2003/09/16 19:51:21 seb Exp $
#

DISTNAME=	tzc-2.6.15
CATEGORIES=	chat net
MASTER_SITES=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/zephyr.html
COMMENT=	Back-end program for zephyr-mode

CPPFLAGS+=      -I/usr/include/kerberosIV -I/usr/include/krb5
LDFLAGS+=       -lroken -lcrypto -lcom_err

USE_BUILDLINK2=	YES

.include "../zephyr/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
