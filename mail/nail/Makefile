# $NetBSD: Makefile,v 1.26 2005/01/13 16:04:00 cjep Exp $

DISTNAME=	nail-11.17
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://nail.sourceforge.net/
COMMENT=	BSD mail utility with MIME extensions

USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes
BUILD_DEFS+=	USE_INET6

MAKE_ENV+=	"SYSCONFDIR=${PKG_SYSCONFDIR}"

.include "../../mk/bsd.prefs.mk"

# IPv6 support
#
.if ${USE_INET6} == "YES"
MAKE_ENV+=	"IPv6=-DHAVE_IPv6_FUNCS"
.endif

.if (${OPSYS} == "SunOS" || ${OPSYS} == "IRIX")
MAKE_ENV+=	"SENDMAIL=/usr/lib/sendmail"
.endif

EGDIR=		${PREFIX}/share/examples/nail

CONF_FILES=     ${EGDIR}/nail.rc ${PKG_SYSCONFDIR}/nail.rc

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/nail ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/nail.1 ${PREFIX}/man/man1
		${INSTALL_DATA_DIR} ${EGDIR}
		${INSTALL_DATA} ${WRKSRC}/nail.rc ${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
