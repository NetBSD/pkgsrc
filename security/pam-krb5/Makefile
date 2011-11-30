# $NetBSD: Makefile,v 1.1.1.1 2011/11/30 23:20:19 pettai Exp $
#

DISTNAME=	pam-krb5-4.4
CATEGORIES=	security
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.eyrie.org/~eagle/software/pam-krb5/
COMMENT=	TODO: Short description of the package
LICENSE=	original-bsd AND gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-krb5-include=/usr/include/krb5

CPPFLAGS.NetBSD+=       -DNO_STATIC_MODULES

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
