# $NetBSD: Makefile,v 1.75 2004/10/03 00:18:01 tv Exp $

DISTNAME=	wget-1.9.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=wget/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/wget/wget.html
COMMENT=	Retrieve files from the 'net via HTTP and FTP

BUILD_USES_MSGFMT=	YES

USE_PERL5=		build
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		ac_cv_func_sigsetjmp=yes

EGDIR=			${PREFIX}/share/examples/wget
CONF_FILES=		${EGDIR}/wgetrc ${PKG_SYSCONFDIR}/wgetrc

INFO_FILES=		wget.info

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		WGET_USE_SSL
.if !empty(WGET_USE_SSL:M[Yy][Ee][Ss])
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=--with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+=--without-ssl
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
