# $NetBSD: Makefile,v 1.3 2016/03/05 11:29:28 jperkin Exp $
#

DISTNAME=	burp-1.4.40
PKGREVISION=	1
CATEGORIES=	sysutils archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=burp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://burp.grke.net
COMMENT=	Networked backup and restore program
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

PKG_SYSCONFSUBDIR=	burp

SUBST_CLASSES+=		dirs
SUBST_STAGE.dirs=	pre-install
SUBST_MESSAGE.dirs=	Fixing directories
SUBST_FILES.dirs=	configs/server/burp.conf \
			configs/server/summary_script \
			configs/client/burp.conf \
			configs/CA/CA.cnf \
			configs/CA/burp_ca \
			manpages/*.8
SUBST_SED.dirs=	-e 's,@LIBEXECDIR@,${PREFIX}/libexec/burp,' \
		-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR:Q},' \
		-e 's,@SBINDIR@,${PREFIX}/sbin,'

REPLACE_SH+=	configs/certs/CA/burp_ca \
		configs/server/notify_script \
		configs/server/timer_script

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q} \
			--mandir=${PREFIX}/${PKGMANDIR} \
			--sbindir=${PREFIX}/sbin

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/burp \
			libexecdir=${PREFIX}/libexec/burp

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/librsync/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
