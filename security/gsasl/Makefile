# $NetBSD: Makefile,v 1.2 2004/02/10 00:17:51 jlam Exp $

DISTNAME=		gsasl-0.0.8
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://josefsson.org/gsasl/releases/ \
			${MASTER_SITE_GNU:=gsasl/}

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gsasl/
COMMENT=		GNU implementation of the Simple Authentication and Security Layer

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

INFO_FILES=		gsasl.info

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/libgsasl.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/libntlm/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../security/gss/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
