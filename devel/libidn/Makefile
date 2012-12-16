# $NetBSD: Makefile,v 1.83 2012/12/16 11:14:34 wiz Exp $

DISTNAME=	libidn-1.26
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/pub/gnu/libidn/ \
		http://ftp.gnu.org/gnu/libidn/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libidn/
COMMENT=	Internationalized Domain Names command line tool
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		makeinfo pkg-config perl:build
TEXINFO_REQD=		4.7
GNU_CONFIGURE=		yes
INFO_FILES=		yes
CONFIGURE_ENV+=		EMACS=${FALSE:Q}
CONFIGURE_ARGS+=	--disable-csharp --disable-java
CONFIGURE_ARGS+=	--with-packager=pkgsrc
CONFIGURE_ARGS+=	--with-packager-bug-reports=http://www.NetBSD.org/cgi-bin/sendpr.cgi?gndb=netbsd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
CONFIGURE_ARGS+=	--disable-ld-version-script
.endif

PKGCONFIG_OVERRIDE+=	libidn.pc.in
TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
