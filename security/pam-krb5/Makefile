# $NetBSD: Makefile,v 1.13 2021/10/21 07:46:38 wiz Exp $

DISTNAME=	pam-krb5-4.6
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.eyrie.org/~eagle/software/pam-krb5/
COMMENT=	Very flexible kerberos module for the PAM framework
LICENSE=	original-bsd OR gnu-gpl-v2

USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
