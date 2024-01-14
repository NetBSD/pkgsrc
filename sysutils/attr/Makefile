# $NetBSD: Makefile,v 1.12 2024/01/14 08:52:30 wiz Exp $

DISTNAME=	attr-2.5.2
CATEGORIES=	sysutils
MASTER_SITES=	https://download.savannah.gnu.org/releases/attr/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/attr
COMMENT=	Commands for Manipulating Filesystem Extended Attributes
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt perl:test
USE_LIBTOOL=		yes
# first test part:
# 119 commands (88 passed, 31 failed)
# second test part (only run as root):
# 30 commands (15 passed, 15 failed)
TEST_TARGET=		check
REPLACE_PERL+=		test/run

PKGCONFIG_OVERRIDE+=	libattr.pc.in
INSTALLATION_DIRS+=	share/examples/attr

CONF_FILES+=	share/examples/attr/xattr.conf ${PKG_SYSCONFDIR}/xattr.conf

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/xattr.conf ${DESTDIR}${PREFIX}/share/examples/attr
	# https://savannah.nongnu.org/bugs/index.php?65161
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3 && \
		${MV} attr_get.3 attr_attr_get.3 && \
		${MV} attr_set.3 attr_attr_set.3

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
