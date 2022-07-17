# $NetBSD: Makefile,v 1.56 2022/07/17 08:24:53 wiz Exp $

DISTNAME=	gsasl-2.0.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNU:=gsasl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/gsasl/
COMMENT=	GNU implementation of the Simple Authentication and Security Layer
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-gssapi-impl=${GSSIMPL.${KRB5_TYPE}}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--with-libgcrypt
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit

PKGCONFIG_OVERRIDE+=	lib/libgsasl.pc.in
INFO_FILES=		yes
TEST_TARGET=		check

# all tests pass as of 2.0.1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/libntlm/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
