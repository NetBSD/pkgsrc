# $NetBSD: Makefile,v 1.36 2008/01/18 05:08:27 tnn Exp $

DISTNAME=	nail-11.25
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://nail.sourceforge.net/
COMMENT=	BSD mail utility with MIME extensions

MAKE_ENV+=	"SYSCONFDIR=${PKG_SYSCONFDIR}"

PKG_OPTIONS_VAR=	PKG_OPTIONS.nail
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=	"IPv6=-DHAVE_IPv6_FUNCS"
.endif

.if (${OPSYS} == "SunOS" || ${OPSYS} == "IRIX")
MAKE_ENV+=	"SENDMAIL=/usr/lib/sendmail"
.endif

EGDIR=		${PREFIX}/share/examples/nail

CONF_FILES=	${EGDIR}/nail.rc ${PKG_SYSCONFDIR}/nail.rc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/nail ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/nail.1 ${PREFIX}/${PKGMANDIR}/man1
		${INSTALL_DATA_DIR} ${EGDIR}
		${INSTALL_DATA} ${WRKSRC}/nail.rc ${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
