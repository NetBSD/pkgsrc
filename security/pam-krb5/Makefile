# $NetBSD: Makefile,v 1.2 2011/12/01 16:04:01 pettai Exp $
#

DISTNAME=	pam-krb5-4.4
CATEGORIES=	security
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.eyrie.org/~eagle/software/pam-krb5/
COMMENT=	Very flexable kerberos module for the PAM framework
LICENSE=	original-bsd OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-krb5-include=/usr/include/krb5

CPPFLAGS.NetBSD+=       -DNO_STATIC_MODULES

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
