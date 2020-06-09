# $NetBSD: Makefile,v 1.14 2020/06/09 10:36:43 nia Exp $
#

DISTNAME=	heirloom-mailx_12.5.orig
PKGNAME=	heirloom-mailx-12.5
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/h/heirloom-mailx/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	jgw@sdf.org
HOMEPAGE=	http://heirloom.sourceforge.net/mailx.html
COMMENT=	BSD mail utility with MIME extensions
LICENSE=	original-bsd AND osl AND mpl-1.1

DEPENDS+=	mime-types-[0-9]*:../../misc/mime-types

WRKSRC=		${WRKDIR}/heirloom-mailx-12.5

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c

MAKE_FLAGS+=		PREFIX=${PREFIX}
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		UCBINSTALL=${INSTALL:Q}
BUILD_MAKE_FLAGS+=	SYSCONFDIR=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}
CPPFLAGS+=		-DMIMEPATH=\"${PKG_SYSCONFDIR}/mime.types\"

.if exists(/usr/include/paths.h)
CPPFLAGS+=		-DHAVE_PATHS_H
.endif

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "SunOS" || ${OPSYS} == "IRIX")
MAKE_FLAGS+=	SENDMAIL=/usr/lib/sendmail
.else
MAKE_FLAGS+=	SENDMAIL=/usr/sbin/sendmail
.endif

.include "options.mk"

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	pre-build
SUBST_FILES.sysconf=	mime.c
SUBST_SED.sysconf=	-e 's;/etc/mime.types;${PKG_SYSCONFDIR}/mime.types;g'

EGDIR=		${PREFIX}/share/examples/mailx

DOCDIR=		${PREFIX}/share/doc/mailx

CONF_FILES=	${EGDIR}/nail.rc ${PKG_SYSCONFDIR}/nail.rc

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
