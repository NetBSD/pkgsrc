# $NetBSD: Makefile,v 1.1.1.1 2002/12/30 17:41:04 sommerfeld Exp $
#

DISTNAME=	tzc-2.6.15
CATEGORIES=	chat net
MASTER_SITES=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/zephyr.html
COMMENT=	Back-end program for zephyr-mode

CPPFLAGS+=      -I/usr/include/kerberosIV -I/usr/include/krb5
LDFLAGS+=       -lroken -lcrypto -lcom_err

USE_BUILDLINK2=	YES

.include "../zephyr-current/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
