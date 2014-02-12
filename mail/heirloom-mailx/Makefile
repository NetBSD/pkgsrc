# $NetBSD: Makefile,v 1.6 2014/02/12 23:18:07 tron Exp $
#

DISTNAME=	mailx-12.4
PKGNAME=	heirloom-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=heirloom/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jgw@freeshell.org
HOMEPAGE=	http://heirloom.sourceforge.net/mailx.html
COMMENT=	BSD mail utility with MIME extensions

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
	${INSTALL_DATA} ${WRKSRC}/mailx.1.html ${DESTDIR}${DOCDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
