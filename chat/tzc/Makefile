# $NetBSD: Makefile,v 1.7 2005/10/18 23:26:56 jlam Exp $
#

DISTNAME=	tzc-2.6.15
PKGREVISION=	1
CATEGORIES=	chat net
MASTER_SITES=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://www-2.cs.cmu.edu/People/dkindred/zephyr-mode/zephyr.html
COMMENT=	Back-end program for zephyr-mode

CPPFLAGS+=      -I/usr/include/kerberosIV -I/usr/include/krb5
LDFLAGS+=       -lroken -lcrypto -lcom_err

.include "../../chat/zephyr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
