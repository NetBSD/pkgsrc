# $NetBSD: Makefile,v 1.17 2006/03/31 23:56:29 jlam Exp $

DISTNAME=		gsasl-0.2.5
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://josefsson.org/gsasl/releases/ \
			${MASTER_SITE_GNU:=gsasl/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gsasl/
COMMENT=		GNU implementation of the Simple Authentication and Security Layer

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
TEST_TARGET=		check

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

PKGCONFIG_OVERRIDE+=    libgsasl.pc.in
INFO_FILES=		# PLIST

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/libntlm/buildlink3.mk"
.include "../../security/gss/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
