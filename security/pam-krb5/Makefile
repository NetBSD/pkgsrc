# $NetBSD: Makefile,v 1.4 2012/03/19 19:31:24 pettai Exp $
#

DISTNAME=	pam-krb5-4.5
CATEGORIES=	security
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.eyrie.org/~eagle/software/pam-krb5/
COMMENT=	Very flexible kerberos module for the PAM framework
LICENSE=	original-bsd OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes

CPPFLAGS.NetBSD+=       -DNO_STATIC_MODULES

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
