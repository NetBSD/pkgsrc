# $NetBSD: Makefile,v 1.9 2016/12/12 14:22:04 wiz Exp $
#

DISTNAME=	pam-krb5-4.6
CATEGORIES=	security
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.eyrie.org/~eagle/software/pam-krb5/
COMMENT=	Very flexible kerberos module for the PAM framework
LICENSE=	original-bsd OR gnu-gpl-v2

USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes

CPPFLAGS.NetBSD+=       -DNO_STATIC_MODULES

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
