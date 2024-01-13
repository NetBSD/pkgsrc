# $NetBSD: Makefile,v 1.9 2024/01/13 19:30:47 wiz Exp $

DISTNAME=	attr-2.5.1
CATEGORIES=	sysutils
MASTER_SITES=	https://download.savannah.gnu.org/releases/attr/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/attr
COMMENT=	Commands for Manipulating Filesystem Extended Attributes
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf automake autopoint autoreconf gmake msgfmt
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	libattr.pc.in
INSTALLATION_DIRS+=	share/examples/attr

CONF_FILES+=	share/examples/attr/xattr.conf ${PKG_SYSCONFDIR}/xattr.conf

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/xattr.conf ${DESTDIR}${PREFIX}/share/examples/attr

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
