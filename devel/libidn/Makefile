# $NetBSD: Makefile,v 1.86 2013/06/15 13:53:49 ryoon Exp $

DISTNAME=	libidn-1.27
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/pub/gnu/libidn/ \
		${MASTER_SITE_GNU:=libidn/}

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
