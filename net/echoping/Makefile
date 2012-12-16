# $NetBSD: Makefile,v 1.26 2012/12/16 01:52:28 obache Exp $
#

DISTNAME=	echoping-6.0.2
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.internatif.org/pub/unix/echoping/ \
		${MASTER_SITE_SOURCEFORGE:=echoping/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://echoping.sourceforge.net/
COMMENT=	Test performance of a remote TCP service

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		YES
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
PLUGINS=		dns random whois
USE_LIBTOOL=		YES

.include "options.mk"

CONFIGURE_ARGS+=	--enable-icp
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-libidn=${BUILDLINK_PREFIX.libidn}
CONFIGURE_ARGS+=	--enable-plugin="${PLUGINS}"

post-build:
	${CP} ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
