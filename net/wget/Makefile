# $NetBSD: Makefile,v 1.68 2003/11/12 03:39:42 jschauma Exp $

DISTNAME=	wget-1.8.2
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=wget/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/wget/wget.html
COMMENT=	Retrieve files from the 'net via HTTP and FTP

BUILD_USES_MSGFMT=	YES

USE_PERL5=		build
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

OPENSSL_LDFLAGS=	${LDFLAGS} -L${BUILDLINK_PREFIX.openssl}/lib \
			-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
FIX_RPATH+=		OPENSSL_LDFLAGS

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		OPENSSL_LDFLAGS="${OPENSSL_LDFLAGS}"

EGDIR=			${PREFIX}/share/examples/wget
CONF_FILES=		${EGDIR}/wgetrc ${PKG_SYSCONFDIR}/wgetrc

INFO_FILES=		wget.info

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		WGET_USE_SSL
.if !empty(WGET_USE_SSL:M[Yy][Ee][Ss])
.include "../../security/openssl/buildlink2.mk"
CONFIGURE_ARGS+=--with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+=--without-ssl
.endif

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
