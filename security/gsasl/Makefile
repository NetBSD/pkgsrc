# $NetBSD: Makefile,v 1.19 2006/12/09 14:06:13 obache Exp $

DISTNAME=		gsasl-0.2.15
CATEGORIES=		security
MASTER_SITES=		http://josefsson.org/gsasl/releases/ \
			ftp://alpha.gnu.org/pub/gnu/gsasl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gsasl/
COMMENT=		GNU implementation of the Simple Authentication and Security Layer

USE_TOOLS+=		msgfmt pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
TEST_TARGET=		check

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--with-libgcrypt
CONFIGURE_ARGS+=	--enable-gssapi=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit

PKGCONFIG_OVERRIDE+=	lib/libgsasl.pc.in
INFO_FILES=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/libntlm/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
