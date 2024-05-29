# $NetBSD: Makefile,v 1.89 2024/05/29 16:31:59 adam Exp $

DISTNAME=	cutter-1.2.4
PKGREVISION=	44
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cutter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cutter.sourceforge.net/
COMMENT=	Unit Testing Framework for C and C++
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool pkg-config xgettext msgmerge msgfmt
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	cppcutter.pc.in
PKGCONFIG_OVERRIDE+=	cutter.pc.in
PKGCONFIG_OVERRIDE+=	gcutter.pc.in
PKGCONFIG_OVERRIDE+=	gdkcutter-pixbuf.pc.in
PKGCONFIG_OVERRIDE+=	libcutter.pc.in
PKGCONFIG_OVERRIDE+=	soupcutter.pc.in

TEST_TARGET=	check

.include "options.mk"

.include "../../mk/compiler.mk"
# PR#lib/39986
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 060000 && ${CC_VERSION:Mgcc*}
LDFLAGS.NetBSD+=	-lgcc_s
.endif

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
