# $NetBSD: Makefile,v 1.33 2026/06/04 16:55:29 gdt Exp $

DISTNAME=	v2.4.2.0-pre0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/v//:S/-pre0/.0/}
PKGREVISION=	27
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=LinearTapeFileSystem/}/${GITHUB_PROJECT}/archive/
GITHUB_PROJECT=	ltfs
DIST_SUBDIR=	${GITHUB_PROJECT}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME:S/v//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/LinearTapeFileSystem/ltfs/
COMMENT=	Linear FileSystem for LTO and DAT tapes
LICENSE=	modified-bsd

# NB: Does not work with perfused from NetBSD <=7 (not supported in
# pkgsrc since 2020, so not annotated).  \todo Revisit after update.

# messages handling is inherently racy and a huge mess
MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoheader automake autoreconf gmake pkg-config
USE_LANGUAGES=	c

REPLACE_SH+=	init.d/ltfs

EGDIR=		${PREFIX}/share/examples/ltfs/
CONF_FILES+=	${EGDIR}/ltfs.conf ${PKG_SYSCONFDIR}/ltfs.conf
CONF_FILES+=	${EGDIR}/ltfs.conf.local ${PKG_SYSCONFDIR}/ltfs.conf.local

BUILDLINK_TRANSFORM+=	rm:-Werror=declaration-after-statement

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/ltfs.conf ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/conf/ltfs.conf.local ${DESTDIR}${EGDIR}/

# net/net-snmp brings -lperl but fails to buildinlink it
# or set approriate -L flag, hence we must help here, despite
# we do not need -lperl.
.include "../../lang/perl5/buildlink3.mk"
LDFLAGS+=               -L${PREFIX}/${PERL5_SUB_INSTALLARCHLIB}/CORE

.include "../../devel/libuuid/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../filesystems/fuse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
