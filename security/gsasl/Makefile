# $NetBSD: Makefile,v 1.11 2005/02/28 13:29:31 wiz Exp $

DISTNAME=		gsasl-0.2.5
CATEGORIES=		security
MASTER_SITES=		http://josefsson.org/gsasl/releases/ \
			${MASTER_SITE_GNU:=gsasl/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gsasl/
COMMENT=		GNU implementation of the Simple Authentication and Security Layer

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
TEST_TARGET=		check

INFO_FILES=		gsasl.info

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

PKGCONFIG_OVERRIDE+=    libgsasl.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/libntlm/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../security/gss/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
