# $NetBSD: Makefile,v 1.9 2023/10/24 22:11:04 wiz Exp $

DISTNAME=	burp-3.2.0
CATEGORIES=	sysutils archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=grke/}
GITHUB_PROJECT=	burp
GITHUB_TAG=	3.2.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://burp.grke.net/
COMMENT=	Networked backup and restore program
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

PKG_SYSCONFSUBDIR=	burp

SUBST_CLASSES+=		dirs
SUBST_STAGE.dirs=	pre-install
SUBST_MESSAGE.dirs=	Fixing directories
SUBST_FILES.dirs=	configs/server/burp.conf.in \
			configs/server/summary_script.in \
			configs/client/burp.conf.in \
			configs/certs/CA/CA.cnf.in \
			configs/certs/CA/burp_ca.in \
			manpages/*.8.in
SUBST_SED.dirs=		-e 's,@LIBEXECDIR@,${PREFIX}/libexec/burp,' \
			-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},' \
			-e 's,@SBINDIR@,${PREFIX}/sbin,'

REPLACE_SH+=	configs/certs/CA/burp_ca.in \
		configs/server/notify_script \
		configs/server/timer_script

USE_TOOLS+=	autoreconf autoconf automake pkg-config
USE_LIBTOOL=	yes

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -vif

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--mandir=${PREFIX}/${PKGMANDIR} \
			--sbindir=${PREFIX}/sbin

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/burp \
			libexecdir=${PREFIX}/libexec/burp

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/librsync/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
