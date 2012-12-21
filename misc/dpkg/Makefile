# $NetBSD: Makefile,v 1.26 2012/12/21 04:55:10 dholland Exp $
#

DISTNAME=	dpkg_1.16.3
PKGNAME=	dpkg-1.16.3
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/d/dpkg/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.debian.org/Teams/Dpkg
COMMENT=	Package maintenance system for Debian

BUILD_DEPENDS+=		po4a>=0:../../textproc/po4a
BUILD_DEPENDS+=		gtar>=1.26:../../archivers/gtar

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_DEFS+=	VARBASE

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake msgfmt perl:run
USE_NCURSES=		yes	# needs tigetstr()

REPLACE_PERL=		scripts/*.pl
REPLACE_PERL+=		dselect/methods/ftp/install
REPLACE_PERL+=		dselect/methods/ftp/setup
REPLACE_PERL+=		dselect/methods/ftp/update

# XXX this is probably not the best way to do this but it'll have to
# serve for the moment.
THIS_PERL_VERSION=	5.16.0
NEXT_PERL_VERSION=	5.18.0
PLIST_SUBST+=		PERL=${THIS_PERL_VERSION}
PERL_DEP=		perl>=${THIS_PERL_VERSION}<${NEXT_PERL_VERSION}
DEPENDS+=		${PERL_DEP}:../../lang/perl5

CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--disable-start-stop-daemon
CONFIGURE_ARGS+=	--with-admindir=${VARBASE}/db/dpkg
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/dpkg

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--enable-linker-optimisations=no
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
